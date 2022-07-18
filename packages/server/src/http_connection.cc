//
// Created by Larry on 2021/12/21.
//

#include "http_connection.h"
#include "handlers/index.h"
#include <iostream>
#include <utility>

void http_connection::read_request() {
  auto self = shared_from_this();

  boost::beast::http::async_read(
      socket_, buffer_, request_,
      [self](boost::beast::error_code ec, std::size_t bytes_transferred) {
        boost::ignore_unused(bytes_transferred);
        if (!ec)
          self->process_request();
      });
}

void http_connection::process_request() {
  response_.version(request_.version());
  response_.keep_alive(false);

  switch (request_.method()) {
  case boost::beast::http::verb::get:
    response_.result(boost::beast::http::status::ok);
    response_.set(boost::beast::http::field::server, "Beast");
    create_response();
    break;

  default:
    // We return responses indicating an error if
    // we do not recognize the request method.
    response_.result(boost::beast::http::status::bad_request);
    response_.set(boost::beast::http::field::content_type, "text/plain");
    boost::beast::ostream(response_.body())
        << "Invalid request-method '" << std::string(request_.method_string())
        << "'";
    break;
  }
}

void http_connection::create_response() {
  std::cout << "query222: " << request_.target() << std::endl;
  auto url = "http://localhost" + request_.target().to_string();

  if (request_.target() == "/count") {
    response_.set(boost::beast::http::field::content_type, "text/html");
    boost::beast::ostream(response_.body())
        << "<html>\n"
        << "<head><title>Request count</title></head>\n"
        << "<body>\n"
        << "<h1>Request count</h1>\n"
        << "<p>There have been "
        << " requests so far.</p>\n"
        << "</body>\n"
        << "</html>\n";
  } else if (request_.target() == "/time") {
    response_.set(boost::beast::http::field::content_type, "text/html");
    boost::beast::ostream(response_.body())
        << "<html>\n"
        << "<head><title>Current time</title></head>\n"
        << "<body>\n"
        << "<h1>Current time</h1>\n"
        << "<p>The current time is "
        << " seconds since the epoch.</p>\n"
        << "</body>\n"
        << "</html>\n";
  } else if (request_.target() == "/") {
    HandleIndex(response_);
    // send_file();
  } else {
    HandleFiles(request_, response_);
  }
  write_response();
}

void http_connection::write_response() {
  auto self = shared_from_this();

  response_.content_length(response_.body().size());

  boost::beast::http::async_write(
      socket_, response_, [self](boost::beast::error_code ec, std::size_t) {
        self->socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);
        self->deadline_.cancel();
      });
}

// void http_connection::send_file()
//{
//     std::string full_path = "static/index.html";
//
//     boost::beast::http::file_body::value_type file;
//     boost::beast::error_code ec;
//     file.open(
//             full_path.c_str(),
//             boost::beast::file_mode::read,
//             ec);
//     if(ec)
//     {
//         std::cout <<"File not found\r\n";
//         return;
//     }
//
//     file_response_.emplace(
//             std::piecewise_construct,
//             std::make_tuple()
//             //std::make_tuple(alloc_)
//             );
//
//     file_response_->result(boost::beast::http::status::ok);
//     file_response_->keep_alive(false);
//     file_response_->set(boost::beast::http::field::server, "Beast");
//     file_response_->set(boost::beast::http::field::content_type,
//     mime_type(std::string(full_path))); file_response_->body() =
//     std::move(file); file_response_->prepare_payload();
//
//     file_serializer_.emplace(*file_response_);
//
//     boost::beast::http::async_write(
//             socket_,
//             *file_serializer_,
//             [this](boost::beast::error_code ec, std::size_t)
//             {
//                 socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_send,
//                 ec); file_serializer_.reset(); file_response_.reset();
//             });
// }

void http_connection::check_deadline() {
  auto self = shared_from_this();

  deadline_.async_wait([self](boost::beast::error_code ec) {
    if (!ec) {
      // Close socket to cancel any outstanding operation.
      self->socket_.close(ec);
    }
  });
}
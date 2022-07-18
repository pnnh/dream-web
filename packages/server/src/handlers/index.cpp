//
// Created by ubuntu on 12/25/21.
//

#include "index.h"
#include <fstream>
#include <iostream>

void HandleFiles(boost::beast::http::request<boost::beast::http::dynamic_body> &request_,
                 boost::beast::http::response<boost::beast::http::dynamic_body> &response_) {
  std::cout << "query222: " << request_.target() << std::endl;

  std::ifstream infile;
  infile.open("static/index.html");

  std::string path = "static/index.html";

  std::string full_path = "static/index.html";

  response_.result(boost::beast::http::status::ok);
  response_.keep_alive(false);
  response_.set(boost::beast::http::field::server, "Beast");
  //  response_.set(boost::beast::http::field::content_type,
  //                mime_type(std::string(full_path)));

  {
    HandleIndex(response_);
    response_.result(boost::beast::http::status::not_found);
    response_.set(boost::beast::http::field::content_type, "text/plain");
    boost::beast::ostream(response_.body()) << "File not found\r\n";
  }

  boost::beast::ostream(response_.body()) << infile.rdbuf();
}

void HandleIndex(boost::beast::http::response<boost::beast::http::dynamic_body> &response_) {
  response_.set(boost::beast::http::field::content_type, "text/html");
  boost::beast::ostream(response_.body())
      << "<html>\n"
      << "<head><title>Current time</title></head>\n"
      << "<body>\n"
      << "<h1>Current time</h1>\n"
      << "<p>The current time is "
      << " seconds since the epoch.</p>\n"
      << "</body>\n"
      << "</html>\n";;
}
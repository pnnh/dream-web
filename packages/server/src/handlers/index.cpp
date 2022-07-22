//
// Created by ubuntu on 12/25/21.
//

#include "index.h"
#include "src/utils/mime.h"
#include <fstream>
#include <iostream>

void HandleFiles(
    boost::beast::http::request<boost::beast::http::dynamic_body> &request_,
    boost::beast::http::response<boost::beast::http::dynamic_body> &response_) {
  std::cout << "query222: " << request_.target() << std::endl;
  std::string resPath = request_.target().to_string();
  std::string fullPath;
  if (resPath.rfind("/assets/qml/qmldir") == 0) {
    fullPath = "cmake-build-webassembly/packages/web/qtwasm/qmldir";
  } else if (resPath.rfind("/assets") == 0) {
    fullPath = "packages/web" + resPath;
  } else {
    fullPath = "cmake-build-webassembly/packages/web" + resPath;
  }

  std::ifstream infile;
  infile.open(fullPath, std::ios::in | std::ios::binary);

  std::cout << "fullPath: " << fullPath << std::endl;
  std::cerr << "Error3: " << infile.fail() << std::endl;

  if (infile.fail()) {
    if (errno == ENOENT) {

      std::cerr << "Error2: " << strerror(ENOENT) << std::endl;
      response_.result(boost::beast::http::status::not_found);
      response_.keep_alive(false);
      response_.set(boost::beast::http::field::server, "Beast");
      return;
    }
    return;
  }

  response_.result(boost::beast::http::status::ok);
  response_.keep_alive(false);
  response_.set(boost::beast::http::field::server, "Beast");
  response_.set(boost::beast::http::field::content_type,
                mime_type(std::string(fullPath)));

  boost::beast::ostream(response_.body()) << infile.rdbuf();
}

void HandleIndex(
    boost::beast::http::response<boost::beast::http::dynamic_body> &response_) {
  std::string fullPath = "cmake-build-webassembly/packages/web/dream-wasm.html";
  std::ifstream infile;
  infile.open(fullPath, std::ios::in | std::ios::binary);
  if (infile.fail()) {
    if (errno == ENOENT) {
      std::cerr << "Error2: " << strerror(ENOENT) << std::endl;
      response_.result(boost::beast::http::status::not_found);
      response_.keep_alive(false);
      response_.set(boost::beast::http::field::server, "Beast");
      return;
    }
    return;
  }

  response_.result(boost::beast::http::status::ok);
  response_.keep_alive(false);
  response_.set(boost::beast::http::field::server, "Beast");
  response_.set(boost::beast::http::field::content_type,
                mime_type(std::string(fullPath)));

  boost::beast::ostream(response_.body()) << infile.rdbuf();
}
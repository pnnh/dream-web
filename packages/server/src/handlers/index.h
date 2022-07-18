//
// Created by ubuntu on 12/25/21.
//

#ifndef CPP_SERVER_INDEX_H
#define CPP_SERVER_INDEX_H

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

void HandleFiles(
    boost::beast::http::request<boost::beast::http::dynamic_body> &request_,
    boost::beast::http::response<boost::beast::http::dynamic_body> &response_);
void HandleIndex(
    boost::beast::http::response<boost::beast::http::dynamic_body> &response);

#endif // CPP_SERVER_INDEX_H

// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/retail/v2/product_service.proto

#include "google/cloud/retail/product_connection.h"
#include "google/cloud/retail/internal/product_connection_impl.h"
#include "google/cloud/retail/internal/product_option_defaults.h"
#include "google/cloud/retail/internal/product_stub_factory.h"
#include "google/cloud/retail/product_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace retail {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ProductServiceConnection::~ProductServiceConnection() = default;

StatusOr<google::cloud::retail::v2::Product>
ProductServiceConnection::CreateProduct(
    google::cloud::retail::v2::CreateProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::retail::v2::Product>
ProductServiceConnection::GetProduct(
    google::cloud::retail::v2::GetProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::retail::v2::Product>
ProductServiceConnection::ListProducts(
    google::cloud::retail::v2::ListProductsRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::retail::v2::Product>>(
      std::move(request),
      [](google::cloud::retail::v2::ListProductsRequest const&) {
        return StatusOr<google::cloud::retail::v2::ListProductsResponse>{};
      },
      [](google::cloud::retail::v2::ListProductsResponse const&) {
        return std::vector<google::cloud::retail::v2::Product>();
      });
}

StatusOr<google::cloud::retail::v2::Product>
ProductServiceConnection::UpdateProduct(
    google::cloud::retail::v2::UpdateProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status ProductServiceConnection::DeleteProduct(
    google::cloud::retail::v2::DeleteProductRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::retail::v2::ImportProductsResponse>>
ProductServiceConnection::ImportProducts(
    google::cloud::retail::v2::ImportProductsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::retail::v2::ImportProductsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::retail::v2::SetInventoryResponse>>
ProductServiceConnection::SetInventory(
    google::cloud::retail::v2::SetInventoryRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::retail::v2::SetInventoryResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::retail::v2::AddFulfillmentPlacesResponse>>
ProductServiceConnection::AddFulfillmentPlaces(
    google::cloud::retail::v2::AddFulfillmentPlacesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::retail::v2::AddFulfillmentPlacesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::retail::v2::RemoveFulfillmentPlacesResponse>>
ProductServiceConnection::RemoveFulfillmentPlaces(
    google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::retail::v2::RemoveFulfillmentPlacesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

std::shared_ptr<ProductServiceConnection> MakeProductServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 ProductServicePolicyOptionList>(options,
                                                                 __func__);
  options = retail_internal::ProductServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = retail_internal::CreateDefaultProductServiceStub(background->cq(),
                                                               options);
  return std::make_shared<retail_internal::ProductServiceConnectionImpl>(
      std::move(background), std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace retail_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<retail::ProductServiceConnection> MakeProductServiceConnection(
    std::shared_ptr<ProductServiceStub> stub, Options options) {
  options = ProductServiceDefaultOptions(std::move(options));
  return std::make_shared<retail_internal::ProductServiceConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail_internal
}  // namespace cloud
}  // namespace google
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
// source: google/cloud/gaming/v1/game_server_clusters_service.proto

#include "google/cloud/gameservices/internal/game_server_clusters_connection_impl.h"
#include "google/cloud/gameservices/internal/game_server_clusters_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace gameservices_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GameServerClustersServiceConnectionImpl::
    GameServerClustersServiceConnectionImpl(
        std::unique_ptr<google::cloud::BackgroundThreads> background,
        std::shared_ptr<gameservices_internal::GameServerClustersServiceStub>
            stub,
        Options const& options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      retry_policy_prototype_(
          options
              .get<gameservices::GameServerClustersServiceRetryPolicyOption>()
              ->clone()),
      backoff_policy_prototype_(
          options
              .get<gameservices::GameServerClustersServiceBackoffPolicyOption>()
              ->clone()),
      idempotency_policy_(
          options
              .get<
                  gameservices::
                      GameServerClustersServiceConnectionIdempotencyPolicyOption>()
              ->clone()),
      polling_policy_prototype_(
          options
              .get<gameservices::GameServerClustersServicePollingPolicyOption>()
              ->clone()) {}

StreamRange<google::cloud::gaming::v1::GameServerCluster>
GameServerClustersServiceConnectionImpl::ListGameServerClusters(
    google::cloud::gaming::v1::ListGameServerClustersRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry =
      std::shared_ptr<gameservices::GameServerClustersServiceRetryPolicy const>(
          retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListGameServerClusters(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::gaming::v1::GameServerCluster>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::gaming::v1::ListGameServerClustersRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::gaming::v1::ListGameServerClustersRequest const&
                    request) {
              return stub->ListGameServerClusters(context, request);
            },
            r, function_name);
      },
      [](google::cloud::gaming::v1::ListGameServerClustersResponse r) {
        std::vector<google::cloud::gaming::v1::GameServerCluster> result(
            r.game_server_clusters().size());
        auto& messages = *r.mutable_game_server_clusters();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::gaming::v1::GameServerCluster>
GameServerClustersServiceConnectionImpl::GetGameServerCluster(
    google::cloud::gaming::v1::GetGameServerClusterRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetGameServerCluster(request),
      [this](grpc::ClientContext& context,
             google::cloud::gaming::v1::GetGameServerClusterRequest const&
                 request) {
        return stub_->GetGameServerCluster(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::gaming::v1::GameServerCluster>>
GameServerClustersServiceConnectionImpl::CreateGameServerCluster(
    google::cloud::gaming::v1::CreateGameServerClusterRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::gaming::v1::GameServerCluster>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::gaming::v1::CreateGameServerClusterRequest const&
                 request) {
        return stub->AsyncCreateGameServerCluster(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::gaming::v1::GameServerCluster>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateGameServerCluster(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::gaming::v1::PreviewCreateGameServerClusterResponse>
GameServerClustersServiceConnectionImpl::PreviewCreateGameServerCluster(
    google::cloud::gaming::v1::PreviewCreateGameServerClusterRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->PreviewCreateGameServerCluster(request),
      [this](grpc::ClientContext& context,
             google::cloud::gaming::v1::
                 PreviewCreateGameServerClusterRequest const& request) {
        return stub_->PreviewCreateGameServerCluster(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::gaming::v1::OperationMetadata>>
GameServerClustersServiceConnectionImpl::DeleteGameServerCluster(
    google::cloud::gaming::v1::DeleteGameServerClusterRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::gaming::v1::OperationMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::gaming::v1::DeleteGameServerClusterRequest const&
                 request) {
        return stub->AsyncDeleteGameServerCluster(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::gaming::v1::OperationMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteGameServerCluster(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::gaming::v1::PreviewDeleteGameServerClusterResponse>
GameServerClustersServiceConnectionImpl::PreviewDeleteGameServerCluster(
    google::cloud::gaming::v1::PreviewDeleteGameServerClusterRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->PreviewDeleteGameServerCluster(request),
      [this](grpc::ClientContext& context,
             google::cloud::gaming::v1::
                 PreviewDeleteGameServerClusterRequest const& request) {
        return stub_->PreviewDeleteGameServerCluster(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::gaming::v1::GameServerCluster>>
GameServerClustersServiceConnectionImpl::UpdateGameServerCluster(
    google::cloud::gaming::v1::UpdateGameServerClusterRequest const& request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::gaming::v1::GameServerCluster>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::gaming::v1::UpdateGameServerClusterRequest const&
                 request) {
        return stub->AsyncUpdateGameServerCluster(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::gaming::v1::GameServerCluster>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateGameServerCluster(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::gaming::v1::PreviewUpdateGameServerClusterResponse>
GameServerClustersServiceConnectionImpl::PreviewUpdateGameServerCluster(
    google::cloud::gaming::v1::PreviewUpdateGameServerClusterRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->PreviewUpdateGameServerCluster(request),
      [this](grpc::ClientContext& context,
             google::cloud::gaming::v1::
                 PreviewUpdateGameServerClusterRequest const& request) {
        return stub_->PreviewUpdateGameServerCluster(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gameservices_internal
}  // namespace cloud
}  // namespace google
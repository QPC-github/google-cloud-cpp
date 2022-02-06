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
// source: google/cloud/contactcenterinsights/v1/contact_center_insights.proto

#include "google/cloud/contactcenterinsights/internal/contact_center_insights_connection_impl.h"
#include "google/cloud/contactcenterinsights/internal/contact_center_insights_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace contactcenterinsights_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ContactCenterInsightsConnectionImpl::ContactCenterInsightsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<contactcenterinsights_internal::ContactCenterInsightsStub>
        stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          contactcenterinsights_internal::ContactCenterInsightsDefaultOptions(
              ContactCenterInsightsConnection::options()))) {}

StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsConnectionImpl::CreateConversation(
    google::cloud::contactcenterinsights::v1::CreateConversationRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateConversation(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 CreateConversationRequest const& request) {
        return stub_->CreateConversation(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsConnectionImpl::UpdateConversation(
    google::cloud::contactcenterinsights::v1::UpdateConversationRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateConversation(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 UpdateConversationRequest const& request) {
        return stub_->UpdateConversation(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsConnectionImpl::GetConversation(
    google::cloud::contactcenterinsights::v1::GetConversationRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetConversation(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 GetConversationRequest const& request) {
        return stub_->GetConversation(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsConnectionImpl::ListConversations(
    google::cloud::contactcenterinsights::v1::ListConversationsRequest
        request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<
      contactcenterinsights::ContactCenterInsightsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListConversations(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::contactcenterinsights::v1::Conversation>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::cloud::contactcenterinsights::v1::
                          ListConversationsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::contactcenterinsights::v1::
                       ListConversationsRequest const& request) {
              return stub->ListConversations(context, request);
            },
            r, function_name);
      },
      [](google::cloud::contactcenterinsights::v1::ListConversationsResponse
             r) {
        std::vector<google::cloud::contactcenterinsights::v1::Conversation>
            result(r.conversations().size());
        auto& messages = *r.mutable_conversations();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

Status ContactCenterInsightsConnectionImpl::DeleteConversation(
    google::cloud::contactcenterinsights::v1::DeleteConversationRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteConversation(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 DeleteConversationRequest const& request) {
        return stub_->DeleteConversation(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::contactcenterinsights::v1::Analysis>>
ContactCenterInsightsConnectionImpl::CreateAnalysis(
    google::cloud::contactcenterinsights::v1::CreateAnalysisRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::contactcenterinsights::v1::Analysis>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::contactcenterinsights::v1::CreateAnalysisRequest const&
              request) {
        return stub->AsyncCreateAnalysis(cq, std::move(context), request);
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
          google::cloud::contactcenterinsights::v1::Analysis>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateAnalysis(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Analysis>
ContactCenterInsightsConnectionImpl::GetAnalysis(
    google::cloud::contactcenterinsights::v1::GetAnalysisRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetAnalysis(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::GetAnalysisRequest const&
                 request) { return stub_->GetAnalysis(context, request); },
      request, __func__);
}

StreamRange<google::cloud::contactcenterinsights::v1::Analysis>
ContactCenterInsightsConnectionImpl::ListAnalyses(
    google::cloud::contactcenterinsights::v1::ListAnalysesRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<
      contactcenterinsights::ContactCenterInsightsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListAnalyses(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::contactcenterinsights::v1::Analysis>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::contactcenterinsights::v1::ListAnalysesRequest const&
              r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::contactcenterinsights::v1::
                       ListAnalysesRequest const& request) {
              return stub->ListAnalyses(context, request);
            },
            r, function_name);
      },
      [](google::cloud::contactcenterinsights::v1::ListAnalysesResponse r) {
        std::vector<google::cloud::contactcenterinsights::v1::Analysis> result(
            r.analyses().size());
        auto& messages = *r.mutable_analyses();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

Status ContactCenterInsightsConnectionImpl::DeleteAnalysis(
    google::cloud::contactcenterinsights::v1::DeleteAnalysisRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteAnalysis(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::contactcenterinsights::v1::DeleteAnalysisRequest const&
              request) { return stub_->DeleteAnalysis(context, request); },
      request, __func__);
}

future<StatusOr<
    google::cloud::contactcenterinsights::v1::ExportInsightsDataResponse>>
ContactCenterInsightsConnectionImpl::ExportInsightsData(
    google::cloud::contactcenterinsights::v1::ExportInsightsDataRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::contactcenterinsights::v1::ExportInsightsDataResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::contactcenterinsights::v1::
                 ExportInsightsDataRequest const& request) {
        return stub->AsyncExportInsightsData(cq, std::move(context), request);
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
          google::cloud::contactcenterinsights::v1::ExportInsightsDataResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ExportInsightsData(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>>
ContactCenterInsightsConnectionImpl::CreateIssueModel(
    google::cloud::contactcenterinsights::v1::CreateIssueModelRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::contactcenterinsights::v1::IssueModel>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::contactcenterinsights::v1::
                 CreateIssueModelRequest const& request) {
        return stub->AsyncCreateIssueModel(cq, std::move(context), request);
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
          google::cloud::contactcenterinsights::v1::IssueModel>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateIssueModel(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>
ContactCenterInsightsConnectionImpl::UpdateIssueModel(
    google::cloud::contactcenterinsights::v1::UpdateIssueModelRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateIssueModel(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 UpdateIssueModelRequest const& request) {
        return stub_->UpdateIssueModel(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>
ContactCenterInsightsConnectionImpl::GetIssueModel(
    google::cloud::contactcenterinsights::v1::GetIssueModelRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetIssueModel(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::contactcenterinsights::v1::GetIssueModelRequest const&
              request) { return stub_->GetIssueModel(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListIssueModelsResponse>
ContactCenterInsightsConnectionImpl::ListIssueModels(
    google::cloud::contactcenterinsights::v1::ListIssueModelsRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ListIssueModels(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 ListIssueModelsRequest const& request) {
        return stub_->ListIssueModels(context, request);
      },
      request, __func__);
}

future<StatusOr<
    google::cloud::contactcenterinsights::v1::DeleteIssueModelMetadata>>
ContactCenterInsightsConnectionImpl::DeleteIssueModel(
    google::cloud::contactcenterinsights::v1::DeleteIssueModelRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::contactcenterinsights::v1::DeleteIssueModelMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::contactcenterinsights::v1::
                 DeleteIssueModelRequest const& request) {
        return stub->AsyncDeleteIssueModel(cq, std::move(context), request);
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
          google::cloud::contactcenterinsights::v1::DeleteIssueModelMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteIssueModel(request), polling_policy(),
      __func__);
}

future<StatusOr<
    google::cloud::contactcenterinsights::v1::DeployIssueModelResponse>>
ContactCenterInsightsConnectionImpl::DeployIssueModel(
    google::cloud::contactcenterinsights::v1::DeployIssueModelRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::contactcenterinsights::v1::DeployIssueModelResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::contactcenterinsights::v1::
                 DeployIssueModelRequest const& request) {
        return stub->AsyncDeployIssueModel(cq, std::move(context), request);
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
          google::cloud::contactcenterinsights::v1::DeployIssueModelResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeployIssueModel(request), polling_policy(),
      __func__);
}

future<StatusOr<
    google::cloud::contactcenterinsights::v1::UndeployIssueModelResponse>>
ContactCenterInsightsConnectionImpl::UndeployIssueModel(
    google::cloud::contactcenterinsights::v1::UndeployIssueModelRequest const&
        request) {
  auto stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::contactcenterinsights::v1::UndeployIssueModelResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::contactcenterinsights::v1::
                 UndeployIssueModelRequest const& request) {
        return stub->AsyncUndeployIssueModel(cq, std::move(context), request);
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
          google::cloud::contactcenterinsights::v1::UndeployIssueModelResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UndeployIssueModel(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Issue>
ContactCenterInsightsConnectionImpl::GetIssue(
    google::cloud::contactcenterinsights::v1::GetIssueRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetIssue(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::GetIssueRequest const&
                 request) { return stub_->GetIssue(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListIssuesResponse>
ContactCenterInsightsConnectionImpl::ListIssues(
    google::cloud::contactcenterinsights::v1::ListIssuesRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ListIssues(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::ListIssuesRequest const&
                 request) { return stub_->ListIssues(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Issue>
ContactCenterInsightsConnectionImpl::UpdateIssue(
    google::cloud::contactcenterinsights::v1::UpdateIssueRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateIssue(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::UpdateIssueRequest const&
                 request) { return stub_->UpdateIssue(context, request); },
      request, __func__);
}

StatusOr<
    google::cloud::contactcenterinsights::v1::CalculateIssueModelStatsResponse>
ContactCenterInsightsConnectionImpl::CalculateIssueModelStats(
    google::cloud::contactcenterinsights::v1::
        CalculateIssueModelStatsRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CalculateIssueModelStats(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 CalculateIssueModelStatsRequest const& request) {
        return stub_->CalculateIssueModelStats(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsConnectionImpl::CreatePhraseMatcher(
    google::cloud::contactcenterinsights::v1::CreatePhraseMatcherRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreatePhraseMatcher(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 CreatePhraseMatcherRequest const& request) {
        return stub_->CreatePhraseMatcher(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsConnectionImpl::GetPhraseMatcher(
    google::cloud::contactcenterinsights::v1::GetPhraseMatcherRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetPhraseMatcher(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 GetPhraseMatcherRequest const& request) {
        return stub_->GetPhraseMatcher(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsConnectionImpl::ListPhraseMatchers(
    google::cloud::contactcenterinsights::v1::ListPhraseMatchersRequest
        request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<
      contactcenterinsights::ContactCenterInsightsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListPhraseMatchers(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::contactcenterinsights::v1::PhraseMatcher>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::cloud::contactcenterinsights::v1::
                          ListPhraseMatchersRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::contactcenterinsights::v1::
                       ListPhraseMatchersRequest const& request) {
              return stub->ListPhraseMatchers(context, request);
            },
            r, function_name);
      },
      [](google::cloud::contactcenterinsights::v1::ListPhraseMatchersResponse
             r) {
        std::vector<google::cloud::contactcenterinsights::v1::PhraseMatcher>
            result(r.phrase_matchers().size());
        auto& messages = *r.mutable_phrase_matchers();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

Status ContactCenterInsightsConnectionImpl::DeletePhraseMatcher(
    google::cloud::contactcenterinsights::v1::DeletePhraseMatcherRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeletePhraseMatcher(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 DeletePhraseMatcherRequest const& request) {
        return stub_->DeletePhraseMatcher(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsConnectionImpl::UpdatePhraseMatcher(
    google::cloud::contactcenterinsights::v1::UpdatePhraseMatcherRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdatePhraseMatcher(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::
                 UpdatePhraseMatcherRequest const& request) {
        return stub_->UpdatePhraseMatcher(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::CalculateStatsResponse>
ContactCenterInsightsConnectionImpl::CalculateStats(
    google::cloud::contactcenterinsights::v1::CalculateStatsRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CalculateStats(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::contactcenterinsights::v1::CalculateStatsRequest const&
              request) { return stub_->CalculateStats(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Settings>
ContactCenterInsightsConnectionImpl::GetSettings(
    google::cloud::contactcenterinsights::v1::GetSettingsRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetSettings(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::GetSettingsRequest const&
                 request) { return stub_->GetSettings(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::Settings>
ContactCenterInsightsConnectionImpl::UpdateSettings(
    google::cloud::contactcenterinsights::v1::UpdateSettingsRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateSettings(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::contactcenterinsights::v1::UpdateSettingsRequest const&
              request) { return stub_->UpdateSettings(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsConnectionImpl::CreateView(
    google::cloud::contactcenterinsights::v1::CreateViewRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateView(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::CreateViewRequest const&
                 request) { return stub_->CreateView(context, request); },
      request, __func__);
}

StatusOr<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsConnectionImpl::GetView(
    google::cloud::contactcenterinsights::v1::GetViewRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetView(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::GetViewRequest const&
                 request) { return stub_->GetView(context, request); },
      request, __func__);
}

StreamRange<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsConnectionImpl::ListViews(
    google::cloud::contactcenterinsights::v1::ListViewsRequest request) {
  request.clear_page_token();
  auto stub = stub_;
  auto retry = std::shared_ptr<
      contactcenterinsights::ContactCenterInsightsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListViews(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::contactcenterinsights::v1::View>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::contactcenterinsights::v1::ListViewsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::contactcenterinsights::v1::
                       ListViewsRequest const& request) {
              return stub->ListViews(context, request);
            },
            r, function_name);
      },
      [](google::cloud::contactcenterinsights::v1::ListViewsResponse r) {
        std::vector<google::cloud::contactcenterinsights::v1::View> result(
            r.views().size());
        auto& messages = *r.mutable_views();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsConnectionImpl::UpdateView(
    google::cloud::contactcenterinsights::v1::UpdateViewRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateView(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::UpdateViewRequest const&
                 request) { return stub_->UpdateView(context, request); },
      request, __func__);
}

Status ContactCenterInsightsConnectionImpl::DeleteView(
    google::cloud::contactcenterinsights::v1::DeleteViewRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteView(request),
      [this](grpc::ClientContext& context,
             google::cloud::contactcenterinsights::v1::DeleteViewRequest const&
                 request) { return stub_->DeleteView(context, request); },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contactcenterinsights_internal
}  // namespace cloud
}  // namespace google
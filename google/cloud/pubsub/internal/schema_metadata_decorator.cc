// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsub/internal/schema_metadata_decorator.h"
#include "google/cloud/internal/api_client_header.h"

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SchemaServiceMetadata::SchemaServiceMetadata(
    std::shared_ptr<SchemaServiceStub> child)
    : child_(std::move(child)),
      x_goog_api_client_(google::cloud::internal::ApiClientHeader()) {}

StatusOr<google::pubsub::v1::Schema> SchemaServiceMetadata::CreateSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::CreateSchemaRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateSchema(context, request);
}

StatusOr<google::pubsub::v1::Schema> SchemaServiceMetadata::GetSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::GetSchemaRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetSchema(context, request);
}

StatusOr<google::pubsub::v1::ListSchemasResponse>
SchemaServiceMetadata::ListSchemas(
    grpc::ClientContext& context,
    google::pubsub::v1::ListSchemasRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListSchemas(context, request);
}

Status SchemaServiceMetadata::DeleteSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::DeleteSchemaRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->DeleteSchema(context, request);
}

StatusOr<google::pubsub::v1::ValidateSchemaResponse>
SchemaServiceMetadata::ValidateSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::ValidateSchemaRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ValidateSchema(context, request);
}

StatusOr<google::pubsub::v1::ValidateMessageResponse>
SchemaServiceMetadata::ValidateMessage(
    grpc::ClientContext& context,
    google::pubsub::v1::ValidateMessageRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ValidateMessage(context, request);
}

void SchemaServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  context.AddMetadata("x-goog-api-client", x_goog_api_client_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google
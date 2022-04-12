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
// source: google/cloud/dialogflow/v2/version.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_VERSIONS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_VERSIONS_CONNECTION_H

#include "google/cloud/dialogflow_es/versions_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace dialogflow_es_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockVersionsConnection : public dialogflow_es::VersionsConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(StreamRange<google::cloud::dialogflow::v2::Version>, ListVersions,
              (google::cloud::dialogflow::v2::ListVersionsRequest request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::dialogflow::v2::Version>, GetVersion,
              (google::cloud::dialogflow::v2::GetVersionRequest const& request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Version>, CreateVersion,
      (google::cloud::dialogflow::v2::CreateVersionRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Version>, UpdateVersion,
      (google::cloud::dialogflow::v2::UpdateVersionRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DeleteVersion,
      (google::cloud::dialogflow::v2::DeleteVersionRequest const& request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_VERSIONS_CONNECTION_H
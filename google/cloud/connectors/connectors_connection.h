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
// source: google/cloud/connectors/v1/connectors_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONNECTORS_CONNECTORS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONNECTORS_CONNECTORS_CONNECTION_H

#include "google/cloud/connectors/connectors_connection_idempotency_policy.h"
#include "google/cloud/connectors/internal/connectors_retry_traits.h"
#include "google/cloud/connectors/internal/connectors_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace connectors {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ConnectorsRetryPolicy = ::google::cloud::internal::TraitBasedRetryPolicy<
    connectors_internal::ConnectorsRetryTraits>;

using ConnectorsLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        connectors_internal::ConnectorsRetryTraits>;

using ConnectorsLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        connectors_internal::ConnectorsRetryTraits>;

/**
 * The `ConnectorsConnection` object for `ConnectorsClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `ConnectorsClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `ConnectorsClient`.
 *
 * To create a concrete instance, see `MakeConnectorsConnection()`.
 *
 * For mocking, see `connectors_mocks::MockConnectorsConnection`.
 */
class ConnectorsConnection {
 public:
  virtual ~ConnectorsConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::connectors::v1::Connection>
  ListConnections(
      google::cloud::connectors::v1::ListConnectionsRequest request);

  virtual StatusOr<google::cloud::connectors::v1::Connection> GetConnection(
      google::cloud::connectors::v1::GetConnectionRequest const& request);

  virtual future<StatusOr<google::cloud::connectors::v1::Connection>>
  CreateConnection(
      google::cloud::connectors::v1::CreateConnectionRequest const& request);

  virtual future<StatusOr<google::cloud::connectors::v1::Connection>>
  UpdateConnection(
      google::cloud::connectors::v1::UpdateConnectionRequest const& request);

  virtual future<StatusOr<google::cloud::connectors::v1::OperationMetadata>>
  DeleteConnection(
      google::cloud::connectors::v1::DeleteConnectionRequest const& request);

  virtual StreamRange<google::cloud::connectors::v1::Provider> ListProviders(
      google::cloud::connectors::v1::ListProvidersRequest request);

  virtual StatusOr<google::cloud::connectors::v1::Provider> GetProvider(
      google::cloud::connectors::v1::GetProviderRequest const& request);

  virtual StreamRange<google::cloud::connectors::v1::Connector> ListConnectors(
      google::cloud::connectors::v1::ListConnectorsRequest request);

  virtual StatusOr<google::cloud::connectors::v1::Connector> GetConnector(
      google::cloud::connectors::v1::GetConnectorRequest const& request);

  virtual StreamRange<google::cloud::connectors::v1::ConnectorVersion>
  ListConnectorVersions(
      google::cloud::connectors::v1::ListConnectorVersionsRequest request);

  virtual StatusOr<google::cloud::connectors::v1::ConnectorVersion>
  GetConnectorVersion(
      google::cloud::connectors::v1::GetConnectorVersionRequest const& request);

  virtual StatusOr<google::cloud::connectors::v1::ConnectionSchemaMetadata>
  GetConnectionSchemaMetadata(
      google::cloud::connectors::v1::GetConnectionSchemaMetadataRequest const&
          request);

  virtual StreamRange<google::cloud::connectors::v1::RuntimeEntitySchema>
  ListRuntimeEntitySchemas(
      google::cloud::connectors::v1::ListRuntimeEntitySchemasRequest request);

  virtual StreamRange<google::cloud::connectors::v1::RuntimeActionSchema>
  ListRuntimeActionSchemas(
      google::cloud::connectors::v1::ListRuntimeActionSchemasRequest request);

  virtual StatusOr<google::cloud::connectors::v1::RuntimeConfig>
  GetRuntimeConfig(
      google::cloud::connectors::v1::GetRuntimeConfigRequest const& request);
};

/**
 * A factory function to construct an object of type `ConnectorsConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of ConnectorsClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `ConnectorsConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::connectors::ConnectorsPolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `ConnectorsConnection` created by
 * this function.
 */
std::shared_ptr<ConnectorsConnection> MakeConnectorsConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace connectors
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONNECTORS_CONNECTORS_CONNECTION_H
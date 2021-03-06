/**
*** Copyright (c) 2016-present,
*** Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp. All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#include "MongoAccountStateCacheStorage.h"
#include "mongo/src/mappers/AccountStateMapper.h"
#include "mongo/src/storages/MongoCacheStorage.h"
#include "catapult/cache_core/AccountStateCache.h"

using namespace bsoncxx::builder::stream;

namespace catapult { namespace mongo { namespace storages {

	namespace {
		struct AccountStateCacheTraits {
			using CacheType = cache::AccountStateCache;
			using CacheDeltaType = cache::AccountStateCacheDelta;
			using KeyType = Address;
			using ModelType = state::AccountState;

			static constexpr const char* Collection_Name = "accounts";
			static constexpr const char* Id_Property_Name = "account.address";

			static auto GetId(const ModelType& accountState) {
				return accountState.Address;
			}

			static auto MapToMongoId(const Address& address) {
				return mappers::ToBinary(address);
			}

			static auto MapToMongoDocument(const state::AccountState& accountState, model::NetworkIdentifier) {
				return mappers::ToDbModel(accountState);
			}

			static void Insert(CacheDeltaType& cache, const bsoncxx::document::view& document) {
				mappers::ToAccountState(document, [&cache](const auto& address, auto height) -> state::AccountState& {
					return cache.addAccount(address, height);
				});
			}
		};
	}

	DEFINE_MONGO_FLAT_CACHE_STORAGE(AccountState, AccountStateCacheTraits)
}}}

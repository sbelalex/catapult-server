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

#pragma once
#include "catapult/model/FacilityCode.h"
#include "catapult/utils/Casting.h"

namespace catapult { namespace validators {

#define COPY_FACILITY_CODE(FACILITY_NAME) FACILITY_NAME = utils::to_underlying_type(model::FacilityCode::FACILITY_NAME)

	/// Possible validation facility codes.
	enum class FacilityCode : uint8_t {
		COPY_FACILITY_CODE(Aggregate),
		COPY_FACILITY_CODE(Core),
		COPY_FACILITY_CODE(Lock),
		COPY_FACILITY_CODE(Mosaic),
		COPY_FACILITY_CODE(Multisig),
		COPY_FACILITY_CODE(Namespace),
		COPY_FACILITY_CODE(Transfer),

		/// Chain facility code.
		Chain = 0xFF,
		/// Consumer facility code.
		Consumer = 0xFE,
		/// Extension facility code.
		Extension = 0x45,
		/// Hash facility code.
		Hash = 0x48,
		/// Signature facility code.
		Signature = 0x53
	};

#undef COPY_FACILITY_CODE
}}

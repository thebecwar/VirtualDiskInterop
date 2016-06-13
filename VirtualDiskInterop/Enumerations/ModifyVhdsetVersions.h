#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public enum class ModifyVhdsetVersions
	{
		Unspecified = MODIFY_VHDSET_UNSPECIFIED,
		SnapshotPath = MODIFY_VHDSET_SNAPSHOT_PATH,
		RemoveSnapshot = MODIFY_VHDSET_REMOVE_SNAPSHOT,
		DefaultSnapshotPath = MODIFY_VHDSET_DEFAULT_SNAPSHOT_PATH,
	};
#endif
}
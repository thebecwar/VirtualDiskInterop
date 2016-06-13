#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public enum class DeleteSnapshotVhdsetVersions
	{
		Unspecified = DELETE_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED,
		Version1 = DELETE_SNAPSHOT_VHDSET_VERSION_1
	};
#endif
}
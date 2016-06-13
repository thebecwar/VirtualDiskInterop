#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public enum class ApplySnapshotVhdsetFlags
	{
		Unspecified = APPLY_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED,
		Version1 = APPLY_SNAPSHOT_VHDSET_VERSION_1
	};
#endif
}
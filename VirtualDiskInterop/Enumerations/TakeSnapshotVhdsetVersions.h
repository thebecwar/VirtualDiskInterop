#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Enumerates the possible versions for parameters for the TakeSnapshotVhdSet function.
	/// </summary>
	public enum class TakeSnapshotVhdsetVersions
	{
		Unspecified = TAKE_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED,
		Version1 = TAKE_SNAPSHOT_VHDSET_VERSION_1,
	};
#endif
}

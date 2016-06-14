#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Contains flags affecting the behavior of the TakeSnapshotVhdSet function.
	/// </summary>
	[Flags()]
	public enum class TakeSnapshotVhdsetFlags
	{
		None = TAKE_SNAPSHOT_VHDSET_FLAG_NONE,
		Writeable = TAKE_SNAPSHOT_VHDSET_FLAG_WRITEABLE
	};
#endif
}

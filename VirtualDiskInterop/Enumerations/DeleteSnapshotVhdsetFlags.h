#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public enum class DeleteSnapshotVhdsetFlags
	{
		None = DELETE_SNAPSHOT_VHDSET_FLAG_NONE,
		PersistRCT = DELETE_SNAPSHOT_VHDSET_FLAG_PERSIST_RCT,
	};
#endif
}
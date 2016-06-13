#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class MergeVirtualDiskFlags
	{
		None = MERGE_VIRTUAL_DISK_FLAG_NONE,
	};
}
#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class CompactVirtualDiskFlags
	{
		None = COMPACT_VIRTUAL_DISK_FLAG_NONE,
	};
}
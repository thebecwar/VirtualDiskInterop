#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class DetachVirtualDiskFlags
	{
		None = DETACH_VIRTUAL_DISK_FLAG_NONE,
	};
}
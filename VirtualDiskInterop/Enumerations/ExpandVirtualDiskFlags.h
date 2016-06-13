#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class ExpandVirtualDiskFlags
	{
		None = EXPAND_VIRTUAL_DISK_FLAG_NONE,
	};
}
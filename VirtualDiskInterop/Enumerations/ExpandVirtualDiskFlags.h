#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) expand request flags.
	/// </summary>
	[Flags()]
	public enum class ExpandVirtualDiskFlags
	{
		None = EXPAND_VIRTUAL_DISK_FLAG_NONE,
	};
}

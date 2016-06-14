#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) detach request flags.
	/// </summary>
	[Flags()]
	public enum class DetachVirtualDiskFlags
	{
		/// <summary>
		/// No flags. Use system defaults.
		/// </summary>
		None = DETACH_VIRTUAL_DISK_FLAG_NONE,
	};
}

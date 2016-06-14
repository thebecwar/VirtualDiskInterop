#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) COMPACT_VIRTUAL_DISK_PARAMETERS structure to use in calls to VHD functions.
	/// </summary>
	public enum class CompactVirtualDiskVersions
	{
		Unspecified = COMPACT_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = COMPACT_VIRTUAL_DISK_VERSION_1,
	};
}

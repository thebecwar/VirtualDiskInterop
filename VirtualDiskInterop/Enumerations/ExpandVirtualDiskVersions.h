#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) EXPAND_VIRTUAL_DISK_PARAMETERS structure to use in calls to VHD functions.
	/// </summary>
	public enum class ExpandVirtualDiskVersions
	{
		Unspecified = EXPAND_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = EXPAND_VIRTUAL_DISK_VERSION_1,
	};
}

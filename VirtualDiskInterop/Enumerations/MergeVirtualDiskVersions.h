#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) MERGE_VIRTUAL_DISK_PARAMETERS structure to use in calls to VHD functions.
	/// </summary>
	public enum class MergeVirtualDiskVersions
	{
		/// <summary>
		/// Not Supported
		/// </summary>
		Unspecified = MERGE_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		
		/// <summary>
		/// The Version1 member structure will be used.
		/// </summary>
		Version1 = MERGE_VIRTUAL_DISK_VERSION_1,
		
		/// <summary>
		/// The Version2 member structure will be used.
		/// This value is not supported until Windows 8 and Windows Server 2012.
		/// </summary>
		Version2 = MERGE_VIRTUAL_DISK_VERSION_2,
	};
}

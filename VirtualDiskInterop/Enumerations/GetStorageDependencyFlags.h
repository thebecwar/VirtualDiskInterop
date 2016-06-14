#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) storage dependency request flags.
	/// </summary>
	[Flags()]
	public enum class GetStorageDependencyFlags
	{
		/// <summary>
		/// No flags specified.
		/// </summary>
		None = GET_STORAGE_DEPENDENCY_FLAG_NONE,
		
		/// <summary>
		/// Return information for volumes or disks hosting the volume specified. 
		/// </summary>
		HostVolumes = GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES,
		
		/// <summary>
		/// The handle provided is to a disk, not a volume or file.
		/// </summary>
		DiskHandle = GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE,
	};
}

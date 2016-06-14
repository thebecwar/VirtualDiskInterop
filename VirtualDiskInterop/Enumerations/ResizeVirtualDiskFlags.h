#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Enumerates the available flags for the ResizeVirtualDisk function.
	/// </summary>
	[Flags()]
	public enum class ResizeVirtualDiskFlags
	{
		/// <summary>
		/// No flags are specified.
		/// </summary>
		None = RESIZE_VIRTUAL_DISK_FLAG_NONE,
		
		/// <summary>
		/// If this flag is set, skip checking the virtual disk's partition table to ensure that this truncation is safe. 
		/// Setting this flag can cause unrecoverable data loss; use with care.
		/// </summary>
		AllowUnsafeVirtualSize = RESIZE_VIRTUAL_DISK_FLAG_ALLOW_UNSAFE_VIRTUAL_SIZE,
		
		/// <summary>
		/// If this flag is set, resize the disk to the smallest virtual size possible without truncating past any existing partitions. 
		/// If this is set, the NewSize member in the RESIZE_VIRTUAL_DISK_PARAMETERS structure must be zero.
		/// </summary>
		ResizeToSmallestSafeVirtualSize = RESIZE_VIRTUAL_DISK_FLAG_RESIZE_TO_SMALLEST_SAFE_VIRTUAL_SIZE
	};
}

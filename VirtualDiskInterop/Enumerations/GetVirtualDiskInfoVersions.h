#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) information retrieval identifiers.
	/// </summary>
	public enum class GetVirtualDiskInfoVersions
	{
		/// <summary>
		/// Reserved. This value should not be used.
		/// </summary>
		Unspecified = GET_VIRTUAL_DISK_INFO_UNSPECIFIED,
		
		/// <summary>
		/// Information related to the virtual disk size, including total size, physical allocation used, block size, and sector size.
		/// </summary>
		Size = GET_VIRTUAL_DISK_INFO_SIZE,
		
		/// <summary>
		/// The unique identifier. This identifier is persistently stored in the virtual disk and will not change even if the virtual disk file is copied to another file.
		/// </summary>
		Identifier = GET_VIRTUAL_DISK_INFO_IDENTIFIER,
		
		/// <summary>
		/// The paths to parent virtual disks. Valid only for differencing virtual disks.
		/// </summary>
		ParentLocation = GET_VIRTUAL_DISK_INFO_PARENT_LOCATION,
		
		/// <summary>
		/// The unique identifier of the parent virtual disk. Valid only for differencing virtual disks.
		/// </summary>
		ParentIdentifier = GET_VIRTUAL_DISK_INFO_PARENT_IDENTIFIER,
		
		/// <summary>
		/// The time stamp of the parent when the child virtual disk was created. Valid only for differencing virtual disks.
		/// </summary>
		ParentTimestamp = GET_VIRTUAL_DISK_INFO_PARENT_TIMESTAMP,
		
		/// <summary>
		/// The device identifier and vendor identifier that identify the type of virtual disk.
		/// </summary>
		VirtualStorageType = GET_VIRTUAL_DISK_INFO_VIRTUAL_STORAGE_TYPE,
		
		/// <summary>
		/// The type of virtual disk.
		/// </summary>
		ProviderSubtype = GET_VIRTUAL_DISK_INFO_PROVIDER_SUBTYPE,
		
		/// <summary>
		/// Indicates whether the virtual disk is 4 KB aligned.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		Is4kAligned = GET_VIRTUAL_DISK_INFO_IS_4K_ALIGNED,
		
		/// <summary>
		/// Details about the physical disk on which the virtual disk resides.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		PhysicalDisk = GET_VIRTUAL_DISK_INFO_PHYSICAL_DISK,
		
		/// <summary>
		/// The physical sector size of the virtual disk.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		PhysicalSectorSize = GET_VIRTUAL_DISK_INFO_VHD_PHYSICAL_SECTOR_SIZE,
		
		/// <summary>
		/// The smallest safe minimum size of the virtual disk.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		SmallestSafeVirtualSize = GET_VIRTUAL_DISK_INFO_SMALLEST_SAFE_VIRTUAL_SIZE,
		
		/// <summary>
		/// The fragmentation level of the virtual disk.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		Fragmentation = GET_VIRTUAL_DISK_INFO_FRAGMENTATION,
		
		/// <summary>
		/// Whether the virtual disk is currently mounted and in use.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		IsLoaded = GET_VIRTUAL_DISK_INFO_IS_LOADED,
		
		/// <summary>
		/// The identifier that is uniquely created when a user first creates the virtual disk to attempt to uniquely identify that virtual disk.
		/// This value is not supported before Windows 8.1 and Windows Server 2012 R2.
		/// </summary>
		VirtualDiskID = GET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID,
#ifdef WIN10SUPPORT
		
		/// <summary>
		/// The state of resilient change tracking (RCT) for the virtual disk.
		/// This value is not supported before Windows 8.1 and Windows Server 2012 R2.
		/// </summary>
		ChangeTrackingState = GET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE
#endif
	};
}

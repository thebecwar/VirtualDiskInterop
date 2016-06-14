#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) SET_VIRTUAL_DISK_INFO structure to use in calls to VHD functions.
	/// </summary>
	public enum class SetVirtualDiskInfoVersions
	{
		/// <summary>
		/// Not used. Will fail the operation.
		/// </summary>
		Unspecified = SET_VIRTUAL_DISK_INFO_UNSPECIFIED,
		
		/// <summary>
		/// Parent information is being set.
		/// </summary>
		ParentPath = SET_VIRTUAL_DISK_INFO_PARENT_PATH,
		
		/// <summary>
		/// A unique identifier is being set.
		/// If the VHD's unique identifier changes as a result of the SET_VIRTUAL_DISK_INFO_IDENTIFIER operation, 
		/// it will break any existing differencing chains on the VHD.
		/// </summary>
		Identifier = SET_VIRTUAL_DISK_INFO_IDENTIFIER,
		
		/// <summary>
		/// Sets the parent file path and the child depth.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		ParentPathWithDepth = SET_VIRTUAL_DISK_INFO_PARENT_PATH_WITH_DEPTH,
		
		/// <summary>
		/// Sets the physical sector size reported by the VHD.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		PhysicalSectorSize = SET_VIRTUAL_DISK_INFO_PHYSICAL_SECTOR_SIZE,
		
		/// <summary>
		/// The identifier that is uniquely created when a user first creates the virtual disk to attempt to uniquely identify that virtual disk.
		/// This value is not supported before Windows 8.1 and Windows Server 2012 R2.
		/// </summary>
		VirtualDiskID = SET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID,

#if WIN10SUPPORT
		/// <summary>
		/// Whether resilient change tracking (RCT) is turned on for the virtual disk.
		/// This value is not supported before Windows 10 and Windows Server 2016 Technical Preview.
		/// </summary>
		ChangeTrackingState = SET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE,
		
		/// <summary>
		/// The parent linkage information that differencing VHDs store. 
		/// Parent linkage information is metadata used to locate and correctly identify the next parent in the virtual disk chain.
		/// This value is not supported before Windows 10 and Windows Server 2016 Technical Preview.
		/// </summary>
		ParentLocation = SET_VIRTUAL_DISK_INFO_PARENT_LOCATOR,
#endif
	};
}

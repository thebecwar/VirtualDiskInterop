#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual disk open request flags.
	/// </summary>
	[Flags()]
	public enum class OpenVirtualDiskFlags
	{
		/// <summary>
		/// No flag specified.
		/// </summary>
		None = OPEN_VIRTUAL_DISK_FLAG_NONE,
		
		/// <summary>
		/// Open the backing store without opening any differencing-chain parents. Used to correct broken parent links.
		/// </summary>
		NoParents = OPEN_VIRTUAL_DISK_FLAG_NO_PARENTS,
		
		/// <summary>
		/// The backing store being opened is an empty file. Do not perform virtual disk verification.
		/// </summary>
		BlankFile = OPEN_VIRTUAL_DISK_FLAG_BLANK_FILE,
		
		/// <summary>
		/// This flag is only specified at boot time to load the system disk during virtual disk boot.  Must be kernel mode to specify this flag.
		/// </summary>
		BootDrive = OPEN_VIRTUAL_DISK_FLAG_BOOT_DRIVE,
		
		/// <summary>
		/// Indicates that the virtual disk should be opened in cached mode. 
		/// By default the virtual disks are opened using FILE_FLAG_NO_BUFFERING and FILE_FLAG_WRITE_THROUGH.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		CachedIO = OPEN_VIRTUAL_DISK_FLAG_CACHED_IO,
		
		/// <summary>
		/// Indicates the VHD file is to be opened without opening any differencing-chain parents 
		/// and the parent chain is to be created manually using the AddVirtualDiskParent function.
		/// This value is not supported before Windows 8 and Windows Server 2012.
		/// </summary>
		CustomDiffChain = OPEN_VIRTUAL_DISK_FLAG_CUSTOM_DIFF_CHAIN,
		
		/// <summary>
		/// This flag causes all backing stores except the leaf backing store to be opened in cached mode.
		/// </summary>
		ParentCachedIo = OPEN_VIRTUAL_DISK_FLAG_PARENT_CACHED_IO,
#ifdef WIN10SUPPORT
		/// <summary>
		/// This flag causes a Vhd Set file to be opened without any virtual disk.
		/// </summary>
		VhdsetFileOnly = OPEN_VIRTUAL_DISK_FLAG_VHDSET_FILE_ONLY
#endif
	};
}

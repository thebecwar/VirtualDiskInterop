#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual disk attach request flags.
	/// </summary>
	[Flags()]
	public enum class AttachVirtualDiskFlags
	{
		/// <summary>
		/// No flags. Use system defaults.
		/// </summary>
		None = ATTACH_VIRTUAL_DISK_FLAG_NONE,
		
		/// <summary>
		/// Attach the virtual disk as read-only.
		/// </summary>
		ReadOnly = ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY,
		
		/// <summary>
		/// Will cause all volumes on the attached virtual disk to be mounted without assigning drive letters to them.
		/// </summary>
		NoDriveLetter = ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER,
		
		/// <summary>
		/// Will decouple the virtual disk lifetime from that of the VirtualDiskHandle. 
		/// The virtual disk will be attached until the DetachVirtualDisk function is called, even if all open handles to the virtual disk are closed.
		/// </summary>
		PermanentLifetime = ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME,
		
		/// <summary>
		/// Indicates that the drive will not be attached to the local system (but rather to a VM).
		/// </summary>
		NoLocalHost = ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST,
		
#ifdef WIN10SUPPORT
		/// <summary>
		/// Do not assign a custom security descriptor to the disk; use the system default.
		/// </summary>
		NoSecurityDescriptor = ATTACH_VIRTUAL_DISK_FLAG_NO_SECURITY_DESCRIPTOR
#endif
	};

}

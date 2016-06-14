#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual disk dependency information flags.
	/// </summary>
	[Flags()]
	public enum class DependentDiskFlags
	{
		/// <summary>
		/// No flags specified. Use system defaults.
		/// </summary>
		None = DEPENDENT_DISK_FLAG_NONE,
		
		/// <summary>
		/// Multiple files backing the virtual disk.
		/// </summary>
		MultipleBackingFiles = DEPENDENT_DISK_FLAG_MULT_BACKING_FILES,
		
		/// <summary>
		/// Fully allocated virtual disk.
		/// </summary>
		FullyAllocated = DEPENDENT_DISK_FLAG_FULLY_ALLOCATED,
		
		/// <summary>
		/// Read-only virtual disk.
		/// </summary>
		ReadOnly = DEPENDENT_DISK_FLAG_READ_ONLY,
		
		/// <summary>
		/// The backing file of the virtual disk is not on a local physical disk.
		/// </summary>
		Remote = DEPENDENT_DISK_FLAG_REMOTE,
		
		/// <summary>
		/// Reserved.
		/// </summary>
		SystemVolume = DEPENDENT_DISK_FLAG_SYSTEM_VOLUME,
		
		/// <summary>
		/// The backing file of the virtual disk is on the system volume.
		/// </summary>
		SystemVolumeParent = DEPENDENT_DISK_FLAG_SYSTEM_VOLUME_PARENT,
		
		/// <summary>
		/// The backing file of the virtual disk is on a removable physical disk.
		/// </summary>
		Removable = DEPENDENT_DISK_FLAG_REMOVABLE,
		
		/// <summary>
		/// Drive letters are not automatically assigned to the volumes on the virtual disk.
		/// </summary>
		NoDriveLetter = DEPENDENT_DISK_FLAG_NO_DRIVE_LETTER,
		
		/// <summary>
		/// The virtual disk is a parent of a differencing chain.
		/// </summary>
		Parent = DEPENDENT_DISK_FLAG_PARENT,
		
		/// <summary>
		/// The virtual disk is not surfaced on (attached to) the local host. For example, it is attached to a guest virtual machine.
		/// </summary>
		NoHostDisk = DEPENDENT_DISK_FLAG_NO_HOST_DISK,
		
		/// <summary>
		/// The lifetime of the virtual disk is not tied to any application or process.
		/// </summary>
		PermanentLifetime = DEPENDENT_DISK_FLAG_PERMANENT_LIFETIME
	};
}

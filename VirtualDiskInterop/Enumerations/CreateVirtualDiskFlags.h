#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual disk creation flags.
	/// </summary>
	[Flags()]
	public enum class CreateVirtualDiskFlags
	{
		/// <summary>
		/// No special creation conditions; system defaults are used.
		/// </summary>
		None = CREATE_VIRTUAL_DISK_FLAG_NONE,
		
		/// <summary>
		/// Pre-allocate all physical space necessary for the size of the virtual disk (e.g. a fixed VHD).
		/// </summary>
		FullPhysicalAllocation = CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION,
		
		/// <summary>
		/// Take ownership of the source disk during create from source disk, to
		/// insure the source disk does not change during the create operation.  The
		/// source disk must also already be offline or read-only (or both).
		/// Ownership is released when create is done.  This also has a side-effect
		/// of disallowing concurrent create from same source disk.  Create will fail
		/// if ownership cannot be obtained or if the source disk is not already
		/// offline or read-only.  This flag is optional, but highly recommended for
		/// creates from source disk.  No effect for other types of create (no effect
		/// for create from source VHD; no effect for create without SourcePath).
		/// </summary>
		PreventWritesToSourceDisk = CREATE_VIRTUAL_DISK_FLAG_PREVENT_WRITES_TO_SOURCE_DISK,
		
		/// <summary>
		/// Do not copy initial virtual disk metadata or block states from the
		/// parent VHD; this is useful if the parent VHD is a stand-in file and the
		/// real parent will be explicitly set later.
		/// </summary>
		DoNotCopyMetadataFromParent = CREATE_VIRTUAL_DISK_FLAG_DO_NOT_COPY_METADATA_FROM_PARENT,
		
		/// <summary>
		/// Create the backing storage disk.
		/// </summary>
		CreateVirtualDiskFlagCreateBackingStorage = CREATE_VIRTUAL_DISK_FLAG_CREATE_BACKING_STORAGE,
		
		/// <summary>
		/// If set, the SourceLimitPath is an change tracking ID, and all data that has changed
		/// since that change tracking ID will be copied from the source. If clear, the
		/// SourceLimitPath is a VHD file path in the source VHD's chain, and
		/// all data that is present in the children of that VHD in the chain
		/// will be copied from the source.
		/// </summary>
		UseChangeTrackingSourceLimit = CREATE_VIRTUAL_DISK_FLAG_USE_CHANGE_TRACKING_SOURCE_LIMIT,
		
		/// <summary>
		/// If set and the parent VHD has change tracking enabled, the child will
		/// have change tracking enabled and will recognize all change tracking
		/// IDs that currently exist in the parent. If clear or if the parent VHD
		/// does not have change tracking available, then change tracking will
		/// not be enabled in the new VHD.
		/// </summary>
		PreserveParentChangeTrackingState = CREATE_VIRTUAL_DISK_FLAG_PRESERVE_PARENT_CHANGE_TRACKING_STATE
	};
}

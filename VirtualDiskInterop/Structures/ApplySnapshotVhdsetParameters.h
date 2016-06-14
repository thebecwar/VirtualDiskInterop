#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	value class ApplySnapshotVhdsetParametersVersion1
	{
	public:
		/// <summary>
		/// The ID of the new snapshot to be applied to the VHD set.
		/// </summary>
		property Guid SnapshotId
		{
			Guid get()
			{
				return this->m_SnapshotId;
			}
			void set(Guid value)
			{
				this->m_SnapshotId = value;
			}
		}
		
		/// <summary>
		/// Indicates whether the current default leaf data should be retained as part of the apply operation. 
		/// When a zero GUID is specified, the apply operation will discard the current default leaf data. 
		/// When a non-zero GUID is specified, the apply operation will convert the default leaf data into a writeable snapshot with the specified ID.
		/// </summary>
		property Guid LeafSnapshotId
		{
			Guid get()
			{
				return this->m_LeafSnapshotId;
			}
			void set(Guid value)
			{
				this->m_LeafSnapshotId = value;
			}
		}
	private:
		Guid m_SnapshotId;
		Guid m_LeafSnapshotId;
	};
	
	/// <summary>
	/// Contains snapshot parameters, indicating information about the new snapshot to be applied.
	/// </summary>
	public value class ApplySnapshotVhdsetParameters
	{
	public:
		/// <summary>
		/// An ApplySnapshotVhdsetVersions enumeration that specifies the version 
		/// of the ApplySnapshotVhdsetParameters structure being passed to or from the VHD functions.
		/// </summary>
		property ApplySnapshotVhdsetVersions Version
		{
			ApplySnapshotVhdsetVersions get()
			{
				return this->m_Version;
			}
			void set(ApplySnapshotVhdsetVersions value)
			{
				this->m_Version = value;
			}
		}
		property ApplySnapshotVhdsetParametersVersion1 Version1
		{
			ApplySnapshotVhdsetParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(ApplySnapshotVhdsetParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		ApplySnapshotVhdsetVersions m_Version;
		ApplySnapshotVhdsetParametersVersion1 m_Version1;
	};
#endif
}

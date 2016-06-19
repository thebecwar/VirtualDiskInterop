#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public value class ApplySnapshotVhdsetParametersVersion1
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
	internal:
		void PopulateNativeStruct(APPLY_SNAPSHOT_VHDSET_PARAMETERS* parameters)
		{
			parameters->Version1.SnapshotId = Helpers::ToGUID(this->m_SnapshotId);
			parameters->Version1.LeafSnapshotId = Helpers::ToGUID(this->m_LeafSnapshotId);
		}
		void ReadNativeStruct(APPLY_SNAPSHOT_VHDSET_PARAMETERS* parameters)
		{
			this->m_SnapshotId = Helpers::FromGUID(parameters->Version1.SnapshotId);
			this->m_LeafSnapshotId = Helpers::FromGUID(parameters->Version1.LeafSnapshotId);
		}
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
	internal:
		APPLY_SNAPSHOT_VHDSET_PARAMETERS* m_NativeData = NULL;
		APPLY_SNAPSHOT_VHDSET_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new APPLY_SNAPSHOT_VHDSET_PARAMETERS();
			this->m_NativeData->Version = (APPLY_SNAPSHOT_VHDSET_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case ApplySnapshotVhdsetVersions::Version1:
				this->m_Version1.PopulateNativeStruct(this->m_NativeData);
				break;
			}
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData)
			{
				if (updateData)
				{
					this->m_Version = (ApplySnapshotVhdsetVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case ApplySnapshotVhdsetVersions::Version1:
						this->m_Version1.ReadNativeStruct(this->m_NativeData);
						break;
					}
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}
	};
#endif
}

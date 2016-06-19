#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public value class DeleteSnapshotVhdsetParametersVersion1
	{
	public:
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
	private:
		Guid m_SnapshotId;
	internal:
		void PopulateNativeStruct(DELETE_SNAPSHOT_VHDSET_PARAMETERS* parameters)
		{
			parameters->Version1.SnapshotId = Helpers::ToGUID(this->m_SnapshotId);
		}
		void ReadNativeStruct(DELETE_SNAPSHOT_VHDSET_PARAMETERS* parameters)
		{
			this->m_SnapshotId = Helpers::FromGUID(parameters->Version1.SnapshotId);
		}
	};

	public value class DeleteSnapshotVhdsetParameters
	{
	public:
		property DeleteSnapshotVhdsetVersions Version
		{
			DeleteSnapshotVhdsetVersions get()
			{
				return this->m_Version;
			}
			void set(DeleteSnapshotVhdsetVersions value)
			{
				this->m_Version = value;
			}
		}
		property DeleteSnapshotVhdsetParametersVersion1 Version1
		{
			DeleteSnapshotVhdsetParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(DeleteSnapshotVhdsetParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		DeleteSnapshotVhdsetVersions m_Version;
		DeleteSnapshotVhdsetParametersVersion1 m_Version1;
	internal:
		DELETE_SNAPSHOT_VHDSET_PARAMETERS* m_NativeData = NULL;
		DELETE_SNAPSHOT_VHDSET_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new DELETE_SNAPSHOT_VHDSET_PARAMETERS();
			this->m_NativeData->Version = (DELETE_SNAPSHOT_VHDSET_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case DeleteSnapshotVhdsetVersions::Version1:
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
					this->m_Version = (DeleteSnapshotVhdsetVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case DeleteSnapshotVhdsetVersions::Version1:
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
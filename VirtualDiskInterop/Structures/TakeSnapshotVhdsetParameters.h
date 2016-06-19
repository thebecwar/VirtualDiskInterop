#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT

	public value class TakeSnapshotVhdsetParametersVersion1
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
		void PopulateNativeStruct(TAKE_SNAPSHOT_VHDSET_PARAMETERS* parameters)
		{
			parameters->Version1.SnapshotId = Helpers::ToGUID(this->m_SnapshotId);
		}
		void ReadNativeStruct(TAKE_SNAPSHOT_VHDSET_PARAMETERS* parameters)
		{
			this->m_SnapshotId = Helpers::FromGUID(parameters->Version1.SnapshotId);
		}
	};

	public value class TakeSnapshotVhdsetParameters
	{
	public:
		property TakeSnapshotVhdsetVersions Version
		{
			TakeSnapshotVhdsetVersions get()
			{
				return this->m_Version;
			}
			void set(TakeSnapshotVhdsetVersions value)
			{
				this->m_Version = value;
			}
		}
		property TakeSnapshotVhdsetParametersVersion1 Version1
		{
			TakeSnapshotVhdsetParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(TakeSnapshotVhdsetParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		TakeSnapshotVhdsetVersions m_Version;
		TakeSnapshotVhdsetParametersVersion1 m_Version1;
	internal:
		TAKE_SNAPSHOT_VHDSET_PARAMETERS* m_NativeData = NULL;
		TAKE_SNAPSHOT_VHDSET_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				this->ReleaseNative(false);
			}
			this->m_NativeData = new TAKE_SNAPSHOT_VHDSET_PARAMETERS();
			this->m_NativeData->Version = (TAKE_SNAPSHOT_VHDSET_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case TakeSnapshotVhdsetVersions::Version1:
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
					this->m_Version = (TakeSnapshotVhdsetVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case TakeSnapshotVhdsetVersions::Version1:
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
#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public value class ModifyVhdsetParametersSnapshotPath
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
		property String^ SnapshotFilePath
		{
			String^ get()
			{
				return this->m_SnapshotFilePath;
			}
			void set(String^ value)
			{
				this->m_SnapshotFilePath = value;
			}
		}
	private:
		Guid m_SnapshotId;
		String^ m_SnapshotFilePath;
		LPWSTR m_NativeSnapshotFilePath;
	internal:
		void PopulateNativeStruct(MODIFY_VHDSET_PARAMETERS* parameters)
		{
			parameters->SnapshotPath.SnapshotId = Helpers::ToGUID(this->m_SnapshotId);
			this->m_NativeSnapshotFilePath = Helpers::AllocString(this->m_SnapshotFilePath);
			parameters->SnapshotPath.SnapshotFilePath = this->m_NativeSnapshotFilePath;
		}
		void ReadNativeStruct(MODIFY_VHDSET_PARAMETERS* parameters)
		{
			this->m_SnapshotId = Helpers::FromGUID(parameters->SnapshotPath.SnapshotId);
			this->m_SnapshotFilePath = gcnew String(parameters->SnapshotPath.SnapshotFilePath);
			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeSnapshotFilePath)
			{
				LocalFree(this->m_NativeSnapshotFilePath);
				this->m_NativeSnapshotFilePath = NULL;
			}
		}
	};

	public value class ModifyVhdsetParameters
	{
	public:
		property ModifyVhdsetVersions Version
		{
			ModifyVhdsetVersions get()
			{
				return this->m_Version;
			}
			void set(ModifyVhdsetVersions value)
			{
				this->m_Version = value;
			}
		}
		property ModifyVhdsetParametersSnapshotPath SnapshotPath
		{
			ModifyVhdsetParametersSnapshotPath get()
			{
				return this->m_SnapshotPath;
			}
			void set(ModifyVhdsetParametersSnapshotPath value)
			{
				this->m_SnapshotPath = value;
			}
		}
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
		property String^ DefaultFilePath
		{
			String^ get()
			{
				return this->m_DefaultFilePath;
			}
			void set(String^ value)
			{
				this->m_DefaultFilePath = value;
			}
		}
	private:
		ModifyVhdsetVersions m_Version;
		ModifyVhdsetParametersSnapshotPath m_SnapshotPath;
		Guid m_SnapshotId;
		String^ m_DefaultFilePath;

		LPWSTR m_NativeDefaultFilePath;
	internal:
		MODIFY_VHDSET_PARAMETERS* m_NativeData = NULL;
		MODIFY_VHDSET_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				this->ReleaseNative(false);
			}
			this->m_NativeData = new MODIFY_VHDSET_PARAMETERS();
			this->m_NativeData->Version = (MODIFY_VHDSET_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case ModifyVhdsetVersions::SnapshotPath:
				this->m_SnapshotPath.PopulateNativeStruct(this->m_NativeData);
				break;
			case ModifyVhdsetVersions::DefaultSnapshotPath:
				this->m_NativeDefaultFilePath = Helpers::AllocString(this->m_DefaultFilePath);
				this->m_NativeData->DefaultFilePath = this->m_NativeDefaultFilePath;
				break;
			case ModifyVhdsetVersions::RemoveSnapshot:
				this->m_NativeData->SnapshotId = Helpers::ToGUID(this->m_SnapshotId);
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
					this->m_Version = (ModifyVhdsetVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case ModifyVhdsetVersions::SnapshotPath:
						this->m_SnapshotPath.ReadNativeStruct(this->m_NativeData);
						break;
					case ModifyVhdsetVersions::DefaultSnapshotPath:
						this->m_DefaultFilePath = gcnew String(this->m_NativeData->DefaultFilePath);
						break;
					case ModifyVhdsetVersions::RemoveSnapshot:
						this->m_SnapshotId = Helpers::FromGUID(this->m_NativeData->SnapshotId);
						break;
					}
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_SnapshotPath.ReleaseNativeData();
			if (this->m_NativeDefaultFilePath)
			{
				LocalFree(this->m_NativeDefaultFilePath);
				this->m_NativeDefaultFilePath = NULL;
			}
		}
	};
#endif
}
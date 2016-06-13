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
				return this->DefaultFilePath;
			}
			void set(String^ value)
			{
				this->DefaultFilePath = value;
			}
		}
	private:
		ModifyVhdsetVersions m_Version;
		ModifyVhdsetParametersSnapshotPath m_SnapshotPath;
		Guid m_SnapshotId;
		String^ m_DefaultFilePath;
	};
#endif
}
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
	};

#endif
}
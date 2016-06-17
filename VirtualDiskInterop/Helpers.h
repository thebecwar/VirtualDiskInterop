#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace VirtualDiskInterop
{
	// private at the class level == internal to the assembly.
	private ref class Helpers
	{
	public:
		// ToGUID and FromGUID from https://msdn.microsoft.com/en-us/library/wb8scw8f.aspx
		static Guid FromGUID(_GUID guid) {
			return Guid(guid.Data1, guid.Data2, guid.Data3,
				guid.Data4[0], guid.Data4[1],
				guid.Data4[2], guid.Data4[3],
				guid.Data4[4], guid.Data4[5],
				guid.Data4[6], guid.Data4[7]);
		}

		static _GUID ToGUID(Guid guid) {
			array<Byte>^ guidData = guid.ToByteArray();
			pin_ptr<Byte> data = &(guidData[0]);
			return *(_GUID *)data;
		}


		String^ ArrayToMultiSz(array<String^>^ data)
		{
			return String::Empty;
		}
		array<String^>^ MultiSzToArray(String^ data)
		{
			return nullptr;
		}


	};
}
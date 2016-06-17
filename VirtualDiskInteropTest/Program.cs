using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using VirtualDiskInterop;

namespace VirtualDiskInteropTest
{
    class Program
    {
        static void Main(string[] args)
        {
            VirtualStorageType storageType = new VirtualStorageType();
            storageType.DeviceId = VirtualStorageDeviceTypes.Vhdx;
            storageType.VendorId = VirtualStorageType.VendorIdMicrosoft;

            string filename = @"C:\Users\Mark.HammerMill\Documents\DeleteThis.vhdx";

            OpenVirtualDiskParameters parameters = new OpenVirtualDiskParameters();
            parameters.Version = OpenVirtualDiskVersions.Version1;

            VirtualDiskSafeHandle diskHandle = new VirtualDiskSafeHandle();

            uint result = VirtualDiskApi.OpenVirtualDisk(storageType, 
                                                         filename, 
                                                         VirtualDiskAccessMasks.None, 
                                                         OpenVirtualDiskFlags.None, 
                                                         parameters, 
                                                         diskHandle);

            GetVirtualDiskInfo info = new GetVirtualDiskInfo();
            info.Version = GetVirtualDiskInfoVersions.Size;
            



            diskHandle.ReleaseHandle();
            diskHandle = null;
        }
    }
}

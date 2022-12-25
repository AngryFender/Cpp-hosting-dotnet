using System;
using System.Runtime.InteropServices;

namespace Dotnet_library
{
    public class Main
    {
        [UnmanagedCallersOnly(EntryPoint = "absolute")]
        public static int Absolute(int value)
        {
            return Math.Abs(value);
        }
    }    
}

// hello-world.cpp : Defines the entry point for the application.
//

#include "hello-world.h"
#include "helpers.h"

using namespace std;
using namespace Microsoft::WRL;

#pragma region Variables
// The number of swap chain back buffers.
const uint8_t g_NumFrames = 3;
// Use WARP adapter (Windows Advanced Rasterization Platform).
bool g_UseWarp = false;

// Define window width/height.
uint32_t g_ClientWidth = 1280;
uint32_t g_ClientHeight = 720;

// Set to true once the DX12 objects have been initialized.
bool g_IsInitialized = false;

#pragma region Window
// OS window handle to display rendered image.
HWND g_hWnd;
// Stores window rectangle data (used to toggle fullscreen state).
RECT g_WindowRect; 
#pragma endregion

#pragma region DX12
// DirectX 12 Objects (ComPtr ==> pointers)

//	DX12 device object
ComPtr<ID3D12Device2> g_Device;
//	Command queue
ComPtr<ID3D12CommandQueue> g_CommandQueue;
//	Swapchain: presents rendered image to window
ComPtr<IDXGISwapChain4> g_SwapChain;
//	Buffer/Texture resource, used to store backbuffers
ComPtr<ID3D12Resource> g_BackBuffers[g_NumFrames];
//	CommandList: records GPU commands (CommandList/CPUThread)
ComPtr<ID3D12GraphicsCommandList> g_CommandList;
//	CommandAllocator: backing memory for recording GPU commands
//		can only be reused once all commands have been recorded
ComPtr<ID3D12CommandAllocator> g_CommandAllocators[g_NumFrames];
ComPtr<ID3D12DescriptorHeap> g_RTVDescriptorHeap;
UINT g_RTVDescriptorSize;
UINT g_CurrentBackBufferIndex;
#pragma endregion

#pragma endregion


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}

#include "memory.h"
#include "Math.h"
#include <xmmintrin.h>
#include <d3d9.h>
#include "global.h"
#include <emmintrin.h>
#include "def.h"


namespace game
{

    static uint64_t gameManager(void) // done 
    {

    uint64_t rax = 0ull, rbx = 0ull, rcx = 0ull, rdx = 0ull, rdi = 0ull, rsi = 0ull, r8 = 0ull, r9 = 0ull, r10 = 0ull, r11 = 0ull, r12 = 0ull, r13 = 0ull, r14 = 0ull, r15 = 0ull, rbp = 0ull;
 
	rax = read<uint64_t>(base + 0x7C2ACD8);
	rax ^= 0x6B;
	rax += 0xFFFFFFFFFFFFFFAA;
	rax = _rotl64(rax, 0x1B);
 
	return rax;
    }



    static uint64_t profileManager() // done 
    {
         auto profileManager = _rotl64(((((read<uintptr_t>(Base + 0x75AAF48) ^ 0x3D) + 0x11DAEF7620B73551i64) ^ 0x57A5CB3CE2A11133i64) + 0x20) + 0xBB18BC80B902B44i64, 0x32) - 5i64;
 
        return read<uint64_t>(profileManager);
    }



    static uint64_t entityList()
    {

    }



    static uintptr_t camera(const uint64_t value) // done 
    {
        	return camera = read<uint64_t>((Memory::read<uint64_t>(value + 0x40) + 460399687213753754i64) ^ 0xDB36CBAB36F5C90Cui64);
    }



    static uint64_t localPlayer()
    {

    }



    static uint64_t localPawn(const uint64_t controller) // done 
    {
    uint64_t rax = controller, rbx = 0ull, rcx = 0ull, rdx = 0ull, rdi = 0ull, rsi = 0ull, r8 = 0ull, r9 = 0ull, r10 = 0ull, r11 = 0ull, r12 = 0ull, r13 = 0ull, r14 = 0ull, r15 = 0ull, rbp = 0ull;
 
	rax = read<uint64_t>(rax + 0x38);
	rax = _rotl64(rax, 0x2);
	rbx = 0x6E2C20B9BADACF18;
	rbx ^= rax;
	rbx += 0xFFFFFFFFFFFFFFD4;
 
	return rbx;
    }




    static uint64_t localTeam()
    {

    }




    static uint64_t replicationinfo(const uint64_t controller) // done 
    {

	uint64_t rax = controller, rbx = 0ull, rcx = 0ull, rdx = 0ull, rdi = 0ull, rsi = 0ull, r8 = 0ull, r9 = 0ull, r10 = 0ull, r11 = 0ull, r12 = 0ull, r13 = 0ull, r14 = 0ull, r15 = 0ull, rbp = 0ull;
 
	rax = read<uint64_t>(rax + 0xA0);
	rax += 0xFFFFFFFFFFFFFFC1;
	rax = _rotl64(rax, 0x24);
	rax += 0xFFFFFFFFFFFFFF93;
 
	return rax;
    }

    auto world_to_screen(vector_3 world_position, vector_2& screen_position) -> bool
    {
	uint64_t fovX_offset = 0x2DC;
	uint64_t fovY_offset = 0x2D4;
	uint64_t mat_offset = 0x80;
 
	uint64_t pViewRight = camera() + mat_offset;
 
	uint64_t b;
	uint64_t v1 = 0xD31271C53E45CA8E, v2 = 0xD515A9C6F8FF5327;
	for (uint32_t i = 0; i < 0x40; i += 0x8) {
		b = (uint64_t)(pViewRight + i);
		b = __ROL8__(b ^ v1, 0x16) ^ v2;
		v1 -= 0xE7E116AC94E36CF;
		v2 += 0x1B77911D5B1428B3;
	}
 
	vector_3 viewRight = *(vector_3*)&(b);
  
	vector_3 viewUp = *(vector_3*)&(b);
  
	vector_3 viewForward = *(vector_3*)&(b);
 
	vector_3 viewTranslation = *(vector_3*)&(b); 
 
	vector_3 temp = world_position - viewTranslation; // translation
	float x = temp.Dot(viewRight); //right
	float y = temp.Dot(viewUp); // up
	float z = temp.Dot(viewForward * -1.f); // forward
 
	uint32_t fovX_ = ((read<uint32_t>(camera() + fovX_offset) - 845876156) ^ 0xFC24F8F8);
	printf("fovX : %d\n", fovX_);
 
	uint32_t fovY_ = _rotr(read<uint32_t>(camera() + fovY_offset) - 39, 6);
	printf("fovX_ : %d\n", fovY_);
 
	float fovX = *(float*)&fovX_;
	float fovY = *(float*)&fovY_;
 
	printf("fovx : %f\n", fovX);
	printf("fovy : %f\n", fovY);
 
	int width = Settings::width;
	int height = Settings::height;
 
	screen_position.x = (width / 2.f) * (1.f + x / -fovX / z); // fovx
	screen_position.y = (height / 2.f) * (1.f - y / -fovY / z); // fovy
	if (screen_position.x < 0.0f || screen_position.x > width)
		return false;
	return z >= 1.0f;
    }



    static uint64_t team_id(const uint64 controller)
    {   

    } 
    

}

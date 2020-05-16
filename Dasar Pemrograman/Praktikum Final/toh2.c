#include <stdio.h>
#define ull unsigned long long

ull findanu(ull k) {
    if(k & 1) return 1;
    else if((k - 2) % 4 == 0) return 2;
    else if((k - 4) % 8 == 0) return 3;
    else if((k - 8) % 16 == 0) return 4;
    else if((k - 16) % 32 == 0) return 5;
    else if((k - 32) % 64 == 0) return 6;
    else if((k - 64) % 128 == 0) return 7;
    else if((k - 128) % 256 == 0) return 8;
    else if((k - 256) % 512 == 0) return 9;
    else if((k - 512) % 1024 == 0) return 10;
    else if((k - 1024) % 2048 == 0) return 11;
    else if((k - 2048) % 4096 == 0) return 12;
    else if((k - 4096) % 8192 == 0) return 13;
    else if((k - 8192) % 16384 == 0) return 14;
    else if((k - 16384) % 32768 == 0) return 15;
    else if((k - 32768) % 65536 == 0) return 16;
    else if((k - 65536) % 131072 == 0) return 17;
    else if((k - 131072) % 262144 == 0) return 18;
    else if((k - 262144) % 524288 == 0) return 19;
    else if((k - 524288) % 1048576 == 0) return 20;
    else if((k - 1048576) % 2097152 == 0) return 21;
    else if((k - 2097152) % 4194304 == 0) return 22;
    else if((k - 4194304) % 8388608 == 0) return 23;
    else if((k - 8388608) % 16777216 == 0) return 24;
    else if((k - 16777216) % 33554432 == 0) return 25;
    else if((k - 33554432) % 67108864 == 0) return 26;
    else if((k - 67108864) % 134217728 == 0) return 27;
    else if((k - 134217728) % 268435456 == 0) return 28;
    else if((k - 268435456) % 536870912 == 0) return 29;
    else if((k - 536870912) % 1073741824 == 0) return 30;
    else if((k - 1073741824) % 2147483648 == 0) return 31;
    else if((k - 2147483648) % 4294967296 == 0) return 32;
    else if((k - 4294967296) % 8589934592 == 0) return 33;
    else if((k - 8589934592) % 17179869184 == 0) return 34;
    else if((k - 17179869184) % 34359738368 == 0) return 35;
    else if((k - 34359738368) % 68719476736 == 0) return 36;
    else if((k - 68719476736) % 137438953472 == 0) return 37;
    else if((k - 137438953472) % 274877906944 == 0) return 38;
    else if((k - 274877906944) % 549755813888 == 0) return 39;
    else if((k - 549755813888) % 1099511627776 == 0) return 40;
    else if((k - 1099511627776) % 2199023255552 == 0) return 41;
    else if((k - 2199023255552) % 4398046511104 == 0) return 42;
    else if((k - 4398046511104) % 8796093022208 == 0) return 43;
    else if((k - 8796093022208) % 17592186044416 == 0) return 44;
    else if((k - 17592186044416) % 35184372088832 == 0) return 45;
    else if((k - 35184372088832) % 70368744177664 == 0) return 46;
    else if((k - 70368744177664) % 140737488355328 == 0) return 47;
    else if((k - 140737488355328) % 281474976710656 == 0) return 48;
    else if((k - 281474976710656) % 562949953421312 == 0) return 49;
    else if((k - 562949953421312) % 1125899906842624 == 0) return 50;
}

char findsourcegenap(ull a, ull k) {
    if(a & 1) {
        if(a == 1) return ((k/2) % 3)+'A';
        else if(a == 3) return (((k - 4) / 8) % 3)+'A';
        else if(a == 5) return (((k - 16) / 32) % 3)+'A';
        else if(a == 7) return (((k - 64) / 128) % 3)+'A';
        else if(a == 9) return (((k - 256) / 512) % 3)+'A';
        else if(a == 11) return (((k - 1024) / 2048) % 3)+'A';
        else if(a == 13) return (((k - 4096) / 8192) % 3)+'A';
        else if(a == 15) return (((k - 16384) / 32768) % 3)+'A';
        else if(a == 17) return (((k - 65536) / 131072) % 3)+'A';
        else if(a == 19) return (((k - 262144) / 524288) % 3)+'A';
        else if(a == 21) return (((k - 1048576) / 2097152) % 3)+'A';
        else if(a == 23) return (((k - 4194304) / 8388608) % 3)+'A';
        else if(a == 25) return (((k - 16777216) / 33554432) % 3)+'A';
        else if(a == 27) return (((k - 67108864) / 134217728) % 3)+'A';
        else if(a == 29) return (((k - 268435456) / 536870912) % 3)+'A';
        else if(a == 31) return (((k - 1073741824) / 2147483648) % 3)+'A';
        else if(a == 33) return (((k - 4294967296) / 8589934592) % 3)+'A';
        else if(a == 35) return (((k - 17179869184) / 34359738368) % 3)+'A';
        else if(a == 37) return (((k - 68719476736) / 137438953472) % 3)+'A';
        else if(a == 39) return (((k - 274877906944) / 549755813888) % 3)+'A';
        else if(a == 41) return (((k - 1099511627776) / 2199023255552) % 3)+'A';
        else if(a == 43) return (((k - 4398046511104) / 8796093022208) % 3)+'A';
        else if(a == 45) return (((k - 17592186044416) / 35184372088832) % 3)+'A';
        else if(a == 47) return (((k - 70368744177664) / 140737488355328) % 3)+'A';
        else if(a == 49) return (((k - 281474976710656) / 562949953421312) % 3)+'A';
    } else {
        if(a == 2) {
            char now = ((k - 2) / 4) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 4) {
            char now = ((k - 8) / 16) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 6) {
            char now = ((k - 32) / 64) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 8) {
            char now = ((k - 128) / 256) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 10) {
            char now = ((k - 512) / 1024) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 12) {
            char now = ((k - 2048) / 4096) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 14) {
            char now = ((k - 8192) / 16384) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 16) {
            char now = ((k - 32768) / 65536) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 18) {
            char now = ((k - 131072) / 262144) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 20) {
            char now = ((k - 524288) / 1048576) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 22) {
            char now = ((k - 2097152) / 4194304) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 24) {
            char now = ((k - 8388608) / 16777216) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 26) {
            char now = ((k - 33554432) / 67108864) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 28) {
            char now = ((k - 134217728) / 268435456) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 30) {
            char now = ((k - 536870912) / 1073741824) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 32) {
            char now = ((k - 2147483648) / 4294967296) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 34) {
            char now = ((k - 8589934592) / 17179869184) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 36) {
            char now = ((k - 34359738368) / 68719476736) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 38) {
            char now = ((k - 137438953472) / 274877906944) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 40) {
            char now = ((k - 549755813888) / 1099511627776) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 42) {
            char now = ((k - 2199023255552) / 4398046511104) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 44) {
            char now = ((k - 8796093022208) / 17592186044416) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 46) {
            char now = ((k - 35184372088832) / 70368744177664) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 48) {
            char now = ((k - 140737488355328) / 281474976710656) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 50) {
            char now = ((k - 562949953421312) / 1125899906842624) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
    }
}

char finddestgenap(ull a, ull k) {
    if(a & 1) {
        if(a == 1) {
            char now = (k / 2) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 3) {
            char now = ((k - 4) / 8) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 5) {
            char now = ((k - 16) / 32) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 7) {
            char now = ((k - 64) / 128) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 9) {
            char now = ((k - 256) / 512) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 11) {
            char now = ((k - 1024) / 2048) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 13) {
            char now = ((k - 4096) / 8192) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 15) {
            char now = ((k - 16384) / 32768) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 17) {
            char now = ((k - 65536) / 131072) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 19) {
            char now = ((k - 262144) / 524288) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 21) {
            char now = ((k - 1048576) / 2097152) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 23) {
            char now = ((k - 4194304) / 8388608) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 25) {
            char now = ((k - 16777216) / 33554432) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 27) {
            char now = ((k - 67108864) / 134217728) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 29) {
            char now = ((k - 268435456) / 536870912) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 31) {
            char now = ((k - 1073741824) / 2147483648) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 33) {
            char now = ((k - 4294967296) / 8589934592) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 35) {
            char now = ((k - 17179869184) / 34359738368) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 37) {
            char now = ((k - 68719476736) / 137438953472) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 39) {
            char now = ((k - 274877906944) / 549755813888) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 41) {
            char now = ((k - 1099511627776) / 2199023255552) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 43) {
            char now = ((k - 4398046511104) / 8796093022208) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 45) {
            char now = ((k - 17592186044416) / 35184372088832) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 47) {
            char now = ((k - 70368744177664) / 140737488355328) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
        else if(a == 49) {
            char now = ((k - 281474976710656) / 562949953421312) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C'-now;
        }
    } else {
        if(a == 2) return 'C' - (((k - 2) / 4) % 3);
        else if(a == 4) return 'C' - (((k - 8) / 16) % 3);
        else if(a == 6) return 'C' - (((k - 32) / 64) % 3);
        else if(a == 8) return 'C' - (((k - 128) / 256) % 3);
        else if(a == 10) return 'C' - (((k - 512) / 1024) % 3);
        else if(a == 12) return 'C' - (((k - 2048) / 4096) % 3);
        else if(a == 14) return 'C' - (((k - 8192) / 16384) % 3);
        else if(a == 16) return 'C' - (((k - 32768) / 65536) % 3);
        else if(a == 18) return 'C' - (((k - 131072) / 262144) % 3);
        else if(a == 20) return 'C' - (((k - 524288) / 1048576) % 3);
        else if(a == 22) return 'C' - (((k - 2097152) / 4194304) % 3);
        else if(a == 24) return 'C' - (((k - 8388608) / 16777216) % 3);
        else if(a == 26) return 'C' - (((k - 33554432) / 67108864) % 3);
        else if(a == 28) return 'C' - (((k - 134217728) / 268435456) % 3);
        else if(a == 30) return 'C' - (((k - 536870912) / 1073741824) % 3);
        else if(a == 32) return 'C' - (((k - 2147483648) / 4294967296) % 3);
        else if(a == 34) return 'C' - (((k - 8589934592) / 17179869184) % 3);
        else if(a == 36) return 'C' - (((k - 34359738368) / 68719476736) % 3);
        else if(a == 38) return 'C' - (((k - 137438953472) / 274877906944) % 3);
        else if(a == 40) return 'C' - (((k - 549755813888) / 1099511627776) % 3);
        else if(a == 42) return 'C' - (((k - 2199023255552) / 4398046511104) % 3);
        else if(a == 44) return 'C' - (((k - 8796093022208) / 17592186044416) % 3);
        else if(a == 46) return 'C' - (((k - 35184372088832) / 70368744177664) % 3);
        else if(a == 48) return 'C' - (((k - 140737488355328) / 281474976710656) % 3);
        else if(a == 50) return 'C' - (((k - 562949953421312) / 1125899906842624) % 3);
    }
}

char findsourceganjil(ull a, ull k) {
    if(a & 1) {
        if(a == 1) {
            char now = (k / 2) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 3) {
            char now = ((k - 4) / 8) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 5) {
            char now = ((k - 16) / 32) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 7) {
            char now = ((k - 64) / 128) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 9) {
            char now = ((k - 256) / 512) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 11) {
            char now = ((k - 1024) / 2048) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 13) {
            char now = ((k - 4096) / 8192) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 15) {
            char now = ((k - 16384) / 32768) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 17) {
            char now = ((k - 65536) / 131072) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 19) {
            char now = ((k - 262144) / 524288) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 21) {
            char now = ((k - 1048576) / 2097152) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 23) {
            char now = ((k - 4194304) / 8388608) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 25) {
            char now = ((k - 16777216) / 33554432) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 27) {
            char now = ((k - 67108864) / 134217728) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 29) {
            char now = ((k - 268435456) / 536870912) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 31) {
            char now = ((k - 1073741824) / 2147483648) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 33) {
            char now = ((k - 4294967296) / 8589934592) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 35) {
            char now = ((k - 17179869184) / 34359738368) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 37) {
            char now = ((k - 68719476736) / 137438953472) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 39) {
            char now = ((k - 274877906944) / 549755813888) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 41) {
            char now = ((k - 1099511627776) / 2199023255552) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 43) {
            char now = ((k - 4398046511104) / 8796093022208) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 45) {
            char now = ((k - 17592186044416) / 35184372088832) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 47) {
            char now = ((k - 70368744177664) / 140737488355328) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
        else if(a == 49) {
            char now = ((k - 281474976710656) / 562949953421312) % 3;
            if(now == 1) now++;
            else if(now == 2) now--;
            return now+'A';
        }
    } else {
        if(a == 2) return (((k - 2) / 4) % 3) + 'A';
        else if(a == 4) return (((k - 8) / 16) % 3) + 'A';
        else if(a == 6) return (((k - 32) / 64) % 3) + 'A';
        else if(a == 8) return (((k - 128) / 256) % 3) + 'A';
        else if(a == 10) return (((k - 512) / 1024) % 3) + 'A';
        else if(a == 12) return (((k - 2048) / 4096) % 3) + 'A';
        else if(a == 14) return (((k - 8192) / 16384) % 3) + 'A';
        else if(a == 16) return (((k - 32768) / 65536) % 3) + 'A';
        else if(a == 18) return (((k - 131072) / 262144) % 3) + 'A';
        else if(a == 20) return (((k - 524288) / 1048576) % 3) + 'A';
        else if(a == 22) return (((k - 2097152) / 4194304) % 3) + 'A';
        else if(a == 24) return (((k - 8388608) / 16777216) % 3) + 'A';
        else if(a == 26) return (((k - 33554432) / 67108864) % 3) + 'A';
        else if(a == 28) return (((k - 134217728) / 268435456) % 3) + 'A';
        else if(a == 30) return (((k - 536870912) / 1073741824) % 3) + 'A';
        else if(a == 32) return (((k - 2147483648) / 4294967296) % 3) + 'A';
        else if(a == 34) return (((k - 8589934592) / 17179869184) % 3) + 'A';
        else if(a == 36) return (((k - 34359738368) / 68719476736) % 3) + 'A';
        else if(a == 38) return (((k - 137438953472) / 274877906944) % 3) + 'A';
        else if(a == 40) return (((k - 549755813888) / 1099511627776) % 3) + 'A';
        else if(a == 42) return (((k - 2199023255552) / 4398046511104) % 3) + 'A';
        else if(a == 44) return (((k - 8796093022208) / 17592186044416) % 3) + 'A';
        else if(a == 46) return (((k - 35184372088832) / 70368744177664) % 3) + 'A';
        else if(a == 48) return (((k - 140737488355328) / 281474976710656) % 3) + 'A';
        else if(a == 50) return (((k - 562949953421312) / 1125899906842624) % 3) + 'A';
    }
}

char finddestganjil(ull a, ull k) {
    if(a & 1) {
        if(a == 1) return 'C' - ((k/2) % 3);
        else if(a == 3) return 'C' - (((k - 4) / 8) % 3);
        else if(a == 5) return 'C' - (((k - 16) / 32) % 3);
        else if(a == 7) return 'C' - (((k - 64) / 128) % 3);
        else if(a == 9) return 'C' - (((k - 256) / 512) % 3);
        else if(a == 11) return 'C' - (((k - 1024) / 2048) % 3);
        else if(a == 13) return 'C' - (((k - 4096) / 8192) % 3);
        else if(a == 15) return 'C' - (((k - 16384) / 32768) % 3);
        else if(a == 17) return 'C' - (((k - 65536) / 131072) % 3);
        else if(a == 19) return 'C' - (((k - 262144) / 524288) % 3);
        else if(a == 21) return 'C' - (((k - 1048576) / 2097152) % 3);
        else if(a == 23) return 'C' - (((k - 4194304) / 8388608) % 3);
        else if(a == 25) return 'C' - (((k - 16777216) / 33554432) % 3);
        else if(a == 27) return 'C' - (((k - 67108864) / 134217728) % 3);
        else if(a == 29) return 'C' - (((k - 268435456) / 536870912) % 3);
        else if(a == 31) return 'C' - (((k - 1073741824) / 2147483648) % 3);
        else if(a == 33) return 'C' - (((k - 4294967296) / 8589934592) % 3);
        else if(a == 35) return 'C' - (((k - 17179869184) / 34359738368) % 3);
        else if(a == 37) return 'C' - (((k - 68719476736) / 137438953472) % 3);
        else if(a == 39) return 'C' - (((k - 274877906944) / 549755813888) % 3);
        else if(a == 41) return 'C' - (((k - 1099511627776) / 2199023255552) % 3);
        else if(a == 43) return 'C' - (((k - 4398046511104) / 8796093022208) % 3);
        else if(a == 45) return 'C' - (((k - 17592186044416) / 35184372088832) % 3);
        else if(a == 47) return 'C' - (((k - 70368744177664) / 140737488355328) % 3);
        else if(a == 49) return 'C' - (((k - 281474976710656) / 562949953421312) % 3);
    } else {
        if(a == 2) {
            char now = ((k - 2) / 4) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 4) {
            char now = ((k - 8) / 16) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 6) {
            char now = ((k - 32) / 64) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 8) {
            char now = ((k - 128) / 256) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 10) {
            char now = ((k - 512) / 1024) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 12) {
            char now = ((k - 2048) / 4096) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 14) {
            char now = ((k - 8192) / 16384) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 16) {
            char now = ((k - 32768) / 65536) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 18) {
            char now = ((k - 131072) / 262144) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 20) {
            char now = ((k - 524288) / 1048576) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 22) {
            char now = ((k - 2097152) / 4194304) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 24) {
            char now = ((k - 8388608) / 16777216) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 26) {
            char now = ((k - 33554432) / 67108864) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 28) {
            char now = ((k - 134217728) / 268435456) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 30) {
            char now = ((k - 536870912) / 1073741824) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 32) {
            char now = ((k - 2147483648) / 4294967296) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 34) {
            char now = ((k - 8589934592) / 17179869184) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 36) {
            char now = ((k - 34359738368) / 68719476736) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 38) {
            char now = ((k - 137438953472) / 274877906944) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 40) {
            char now = ((k - 549755813888) / 1099511627776) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 42) {
            char now = ((k - 2199023255552) / 4398046511104) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 44) {
            char now = ((k - 8796093022208) / 17592186044416) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 46) {
            char now = ((k - 35184372088832) / 70368744177664) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 48) {
            char now = ((k - 140737488355328) / 281474976710656) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
        else if(a == 50) {
            char now = ((k - 562949953421312) / 1125899906842624) % 3;
            if(now == 0) now++;
            else if(now == 1) now--;
            return 'C' - now;
        }
    }
}

int main() {
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        ull n, k;
        scanf("%llu %llu", &n, &k);
        char source = 'A', dest='A';
        int anu=findanu(k);
        if(n & 1) {
            source = findsourceganjil(anu, k);
            dest = finddestganjil(anu, k);
        } else {
            source = findsourcegenap(anu, k);
            dest = finddestgenap(anu, k);
        }
        printf("%d : %c => %c\n", anu, source, dest);
    }
    return 0;
}
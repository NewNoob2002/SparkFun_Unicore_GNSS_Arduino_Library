#ifndef _SPARKFUN_UNICORE_STRUCTS_H
#define _SPARKFUN_UNICORE_STRUCTS_H

typedef struct
{

    uint8_t positionType; // 0 = None, 1 = FixedPos, 8 = DopplerVelocity, 16 = Single, ...
    double latitude;
    double longitude;
    double altitude;
    float latitudeDeviation;
    float longitudeDeviation;
    float heightDeviation;

    uint8_t satellitesTracked;
    uint8_t satellitesUsed;

    uint8_t rtkSolution = 0;
    uint8_t pseudorangeCorrection = 0;

    uint8_t
        solutionStatus; // 0 = Solution computed, 1 = Insufficient observation, 3 = No convergence, 4 = Covariance trace

    // uint8_t extSolStat;
    // memcpy(&extSolStat, &data[offsetBestnavExtSolStat], sizeof(uint8_t));
    // rtkSolution = extSolStat & 0x01; // 0 = checked, 1 = unchecked
    // pseudorangeCorrection = extSolStat >> 1;

    //  union
    //  {
    //    uint8_t all;
    //    struct
    //    {
    //      uint8_t gnssFixOK : 1; // 1 = valid fix (i.e within DOP & accuracy masks)
    //      uint8_t diffSoln : 1;  // 1 = differential corrections were applied
    //      uint8_t psmState : 3;
    //      uint8_t headVehValid : 1; // 1 = heading of vehicle is valid, only set if the receiver is in sensor fusion
    //      mode uint8_t carrSoln : 2;     // Carrier phase range solution status:
    //                                // 0: no carrier phase range solution
    //                                // 1: carrier phase range solution with floating ambiguities
    //                                // 2: carrier phase range solution with fixed ambiguities
    //    } bits;
    //  } flags;

} UNICORE_BESTNAV_data_t;

typedef struct
{
  union
  {
    uint32_t all;
    struct
    {
      uint32_t all : 1;

      uint32_t solutionStatus : 1;
      uint32_t positionType : 1;
      uint32_t latitude : 1;
      uint32_t longitude : 1;
      uint32_t altitude : 1;
      uint32_t latitudeDeviation : 1;
      uint32_t longitudeDeviation : 1;

      uint32_t heightDeviation : 1;
      uint32_t satellitesTracked : 1;
      uint32_t satellitesUsed : 1;
      uint32_t validMag : 1;

      uint32_t rtkSolution : 1;
      uint32_t pseudorangeCorrection : 1;
    } bits;
  };
} UNICORE_BESTNAV_moduleQueried_t;

typedef struct
{
    // ubxAutomaticFlags automaticFlags;
    UNICORE_BESTNAV_data_t data;
    UNICORE_BESTNAV_moduleQueried_t moduleQueried;
    void (*callbackPointerPtr)(UNICORE_BESTNAV_data_t *);
    UNICORE_BESTNAV_data_t *callbackData;
} UNICORE_BESTNAV_t;

//From Unicore Reference Command Manual
const unsigned long crcTable32[256] = {
    0x00000000UL, 0x77073096UL, 0xEE0E612CUL, 0x990951BAUL, 0x076DC419UL, 0x706AF48FUL, 0xE963A535UL, 0x9E6495A3UL,
    0x0EDB8832UL, 0x79DCB8A4UL, 0xE0D5E91EUL, 0x97D2D988UL, 0x09B64C2BUL, 0x7EB17CBDUL, 0xE7B82D07UL, 0x90BF1D91UL,
    0x1DB71064UL, 0x6AB020F2UL, 0xF3B97148UL, 0x84BE41DEUL, 0x1ADAD47DUL, 0x6DDDE4EBUL, 0xF4D4B551UL, 0x83D385C7UL,
    0x136C9856UL, 0x646BA8C0UL, 0xFD62F97AUL, 0x8A65C9ECUL, 0x14015C4FUL, 0x63066CD9UL, 0xFA0F3D63UL, 0x8D080DF5UL,
    0x3B6E20C8UL, 0x4C69105EUL, 0xD56041E4UL, 0xA2677172UL, 0x3C03E4D1UL, 0x4B04D447UL, 0xD20D85FDUL, 0xA50AB56BUL,
    0x35B5A8FAUL, 0x42B2986CUL, 0xDBBBC9D6UL, 0xACBCF940UL, 0x32D86CE3UL, 0x45DF5C75UL, 0xDCD60DCFUL, 0xABD13D59UL,
    0x26D930ACUL, 0x51DE003AUL, 0xC8D75180UL, 0xBFD06116UL, 0x21B4F4B5UL, 0x56B3C423UL, 0xCFBA9599UL, 0xB8BDA50FUL,
    0x2802B89EUL, 0x5F058808UL, 0xC60CD9B2UL, 0xB10BE924UL, 0x2F6F7C87UL, 0x58684C11UL, 0xC1611DABUL, 0xB6662D3DUL,
    0x76DC4190UL, 0x01DB7106UL, 0x98D220BCUL, 0xEFD5102AUL, 0x71B18589UL, 0x06B6B51FUL, 0x9FBFE4A5UL, 0xE8B8D433UL,
    0x7807C9A2UL, 0x0F00F934UL, 0x9609A88EUL, 0xE10E9818UL, 0x7F6A0DBBUL, 0x086D3D2DUL, 0x91646C97UL, 0xE6635C01UL,
    0x6B6B51F4UL, 0x1C6C6162UL, 0x856530D8UL, 0xF262004EUL, 0x6C0695EDUL, 0x1B01A57BUL, 0x8208F4C1UL, 0xF50FC457UL,
    0x65B0D9C6UL, 0x12B7E950UL, 0x8BBEB8EAUL, 0xFCB9887CUL, 0x62DD1DDFUL, 0x15DA2D49UL, 0x8CD37CF3UL, 0xFBD44C65UL,
    0x4DB26158UL, 0x3AB551CEUL, 0xA3BC0074UL, 0xD4BB30E2UL, 0x4ADFA541UL, 0x3DD895D7UL, 0xA4D1C46DUL, 0xD3D6F4FBUL,
    0x4369E96AUL, 0x346ED9FCUL, 0xAD678846UL, 0xDA60B8D0UL, 0x44042D73UL, 0x33031DE5UL, 0xAA0A4C5FUL, 0xDD0D7CC9UL,
    0x5005713CUL, 0x270241AAUL, 0xBE0B1010UL, 0xC90C2086UL, 0x5768B525UL, 0x206F85B3UL, 0xB966D409UL, 0xCE61E49FUL,
    0x5EDEF90EUL, 0x29D9C998UL, 0xB0D09822UL, 0xC7D7A8B4UL, 0x59B33D17UL, 0x2EB40D81UL, 0xB7BD5C3BUL, 0xC0BA6CADUL,
    0xEDB88320UL, 0x9ABFB3B6UL, 0x03B6E20CUL, 0x74B1D29AUL, 0xEAD54739UL, 0x9DD277AFUL, 0x04DB2615UL, 0x73DC1683UL,
    0xE3630B12UL, 0x94643B84UL, 0x0D6D6A3EUL, 0x7A6A5AA8UL, 0xE40ECF0BUL, 0x9309FF9DUL, 0x0A00AE27UL, 0x7D079EB1UL,
    0xF00F9344UL, 0x8708A3D2UL, 0x1E01F268UL, 0x6906C2FEUL, 0xF762575DUL, 0x806567CBUL, 0x196C3671UL, 0x6E6B06E7UL,
    0xFED41B76UL, 0x89D32BE0UL, 0x10DA7A5AUL, 0x67DD4ACCUL, 0xF9B9DF6FUL, 0x8EBEEFF9UL, 0x17B7BE43UL, 0x60B08ED5UL,
    0xD6D6A3E8UL, 0xA1D1937EUL, 0x38D8C2C4UL, 0x4FDFF252UL, 0xD1BB67F1UL, 0xA6BC5767UL, 0x3FB506DDUL, 0x48B2364BUL,
    0xD80D2BDAUL, 0xAF0A1B4CUL, 0x36034AF6UL, 0x41047A60UL, 0xDF60EFC3UL, 0xA867DF55UL, 0x316E8EEFUL, 0x4669BE79UL,
    0xCB61B38CUL, 0xBC66831AUL, 0x256FD2A0UL, 0x5268E236UL, 0xCC0C7795UL, 0xBB0B4703UL, 0x220216B9UL, 0x5505262FUL,
    0xC5BA3BBEUL, 0xB2BD0B28UL, 0x2BB45A92UL, 0x5CB36A04UL, 0xC2D7FFA7UL, 0xB5D0CF31UL, 0x2CD99E8BUL, 0x5BDEAE1DUL,
    0x9B64C2B0UL, 0xEC63F226UL, 0x756AA39CUL, 0x026D930AUL, 0x9C0906A9UL, 0xEB0E363FUL, 0x72076785UL, 0x05005713UL,
    0x95BF4A82UL, 0xE2B87A14UL, 0x7BB12BAEUL, 0x0CB61B38UL, 0x92D28E9BUL, 0xE5D5BE0DUL, 0x7CDCEFB7UL, 0x0BDBDF21UL,
    0x86D3D2D4UL, 0xF1D4E242UL, 0x68DDB3F8UL, 0x1FDA836EUL, 0x81BE16CDUL, 0xF6B9265BUL, 0x6FB077E1UL, 0x18B74777UL,
    0x88085AE6UL, 0xFF0F6A70UL, 0x66063BCAUL, 0x11010B5CUL, 0x8F659EFFUL, 0xF862AE69UL, 0x616BFFD3UL, 0x166CCF45UL,
    0xA00AE278UL, 0xD70DD2EEUL, 0x4E048354UL, 0x3903B3C2UL, 0xA7672661UL, 0xD06016F7UL, 0x4969474DUL, 0x3E6E77DBUL,
    0xAED16A4AUL, 0xD9D65ADCUL, 0x40DF0B66UL, 0x37D83BF0UL, 0xA9BCAE53UL, 0xDEBB9EC5UL, 0x47B2CF7FUL, 0x30B5FFE9UL,
    0xBDBDF21CUL, 0xCABAC28AUL, 0x53B39330UL, 0x24B4A3A6UL, 0xBAD03605UL, 0xCDD70693UL, 0x54DE5729UL, 0x23D967BFUL,
    0xB3667A2EUL, 0xC4614AB8UL, 0x5D681B02UL, 0x2A6F2B94UL, 0xB40BBE37UL, 0xC30C8EA1UL, 0x5A05DF1BUL, 0x2D02EF8DUL};

#define COMPUTE_CRC32(parse, data)  (((parse)->check << 8) ^ crcTable32[data ^ (((parse)->check >> 16) & 0xFF)])

/*
   This is an implementation of the CRC-24Q cyclic redundancy checksum
   used by Qualcomm, RTCM104V3, and PGP 6.5.1. According to the RTCM104V3
   standard, it uses the error polynomial

      x^24+ x^23+ x^18+ x^17+ x^14+ x^11+ x^10+ x^7+ x^6+ x^5+ x^4+ x^3+ x+1

   This corresponds to a mask of 0x1864CFB.  For a primer on CRC theory,
   including detailed discussion of how and why the error polynomial is
   expressed by this mask, see <http://www.ross.net/crc/>.

   1) It detects all single bit errors per 24-bit code word.
   2) It detects all double bit error combinations in a code word.
   3) It detects any odd number of errors.
   4) It detects any burst error for which the length of the burst is less than
      or equal to 24 bits.
   5) It detects most large error bursts with length greater than 24 bits;
      the odds of a false positive are at most 2^-23.

   This hash should not be considered cryptographically secure, but it
   is extremely good at detecting noise errors.

   Note that this version has a seed of 0 wired in.  The RTCM104V3 standard
   requires this.

   This file is Copyright 2008 by the GPSD project
   SPDX-License-Identifier: BSD-2-clause
*/

//This file is originally from: https://gitlab.com/gpsd/gpsd/-/blob/master/gpsd/crc24q.c

static const int unsigned crc24q[256] = {
  0x00000000u, 0x01864CFBu, 0x028AD50Du, 0x030C99F6u,
  0x0493E6E1u, 0x0515AA1Au, 0x061933ECu, 0x079F7F17u,
  0x08A18139u, 0x0927CDC2u, 0x0A2B5434u, 0x0BAD18CFu,
  0x0C3267D8u, 0x0DB42B23u, 0x0EB8B2D5u, 0x0F3EFE2Eu,
  0x10C54E89u, 0x11430272u, 0x124F9B84u, 0x13C9D77Fu,
  0x1456A868u, 0x15D0E493u, 0x16DC7D65u, 0x175A319Eu,
  0x1864CFB0u, 0x19E2834Bu, 0x1AEE1ABDu, 0x1B685646u,
  0x1CF72951u, 0x1D7165AAu, 0x1E7DFC5Cu, 0x1FFBB0A7u,
  0x200CD1E9u, 0x218A9D12u, 0x228604E4u, 0x2300481Fu,
  0x249F3708u, 0x25197BF3u, 0x2615E205u, 0x2793AEFEu,
  0x28AD50D0u, 0x292B1C2Bu, 0x2A2785DDu, 0x2BA1C926u,
  0x2C3EB631u, 0x2DB8FACAu, 0x2EB4633Cu, 0x2F322FC7u,
  0x30C99F60u, 0x314FD39Bu, 0x32434A6Du, 0x33C50696u,
  0x345A7981u, 0x35DC357Au, 0x36D0AC8Cu, 0x3756E077u,
  0x38681E59u, 0x39EE52A2u, 0x3AE2CB54u, 0x3B6487AFu,
  0x3CFBF8B8u, 0x3D7DB443u, 0x3E712DB5u, 0x3FF7614Eu,
  0x4019A3D2u, 0x419FEF29u, 0x429376DFu, 0x43153A24u,
  0x448A4533u, 0x450C09C8u, 0x4600903Eu, 0x4786DCC5u,
  0x48B822EBu, 0x493E6E10u, 0x4A32F7E6u, 0x4BB4BB1Du,
  0x4C2BC40Au, 0x4DAD88F1u, 0x4EA11107u, 0x4F275DFCu,
  0x50DCED5Bu, 0x515AA1A0u, 0x52563856u, 0x53D074ADu,
  0x544F0BBAu, 0x55C94741u, 0x56C5DEB7u, 0x5743924Cu,
  0x587D6C62u, 0x59FB2099u, 0x5AF7B96Fu, 0x5B71F594u,
  0x5CEE8A83u, 0x5D68C678u, 0x5E645F8Eu, 0x5FE21375u,
  0x6015723Bu, 0x61933EC0u, 0x629FA736u, 0x6319EBCDu,
  0x648694DAu, 0x6500D821u, 0x660C41D7u, 0x678A0D2Cu,
  0x68B4F302u, 0x6932BFF9u, 0x6A3E260Fu, 0x6BB86AF4u,
  0x6C2715E3u, 0x6DA15918u, 0x6EADC0EEu, 0x6F2B8C15u,
  0x70D03CB2u, 0x71567049u, 0x725AE9BFu, 0x73DCA544u,
  0x7443DA53u, 0x75C596A8u, 0x76C90F5Eu, 0x774F43A5u,
  0x7871BD8Bu, 0x79F7F170u, 0x7AFB6886u, 0x7B7D247Du,
  0x7CE25B6Au, 0x7D641791u, 0x7E688E67u, 0x7FEEC29Cu,
  0x803347A4u, 0x81B50B5Fu, 0x82B992A9u, 0x833FDE52u,
  0x84A0A145u, 0x8526EDBEu, 0x862A7448u, 0x87AC38B3u,
  0x8892C69Du, 0x89148A66u, 0x8A181390u, 0x8B9E5F6Bu,
  0x8C01207Cu, 0x8D876C87u, 0x8E8BF571u, 0x8F0DB98Au,
  0x90F6092Du, 0x917045D6u, 0x927CDC20u, 0x93FA90DBu,
  0x9465EFCCu, 0x95E3A337u, 0x96EF3AC1u, 0x9769763Au,
  0x98578814u, 0x99D1C4EFu, 0x9ADD5D19u, 0x9B5B11E2u,
  0x9CC46EF5u, 0x9D42220Eu, 0x9E4EBBF8u, 0x9FC8F703u,
  0xA03F964Du, 0xA1B9DAB6u, 0xA2B54340u, 0xA3330FBBu,
  0xA4AC70ACu, 0xA52A3C57u, 0xA626A5A1u, 0xA7A0E95Au,
  0xA89E1774u, 0xA9185B8Fu, 0xAA14C279u, 0xAB928E82u,
  0xAC0DF195u, 0xAD8BBD6Eu, 0xAE872498u, 0xAF016863u,
  0xB0FAD8C4u, 0xB17C943Fu, 0xB2700DC9u, 0xB3F64132u,
  0xB4693E25u, 0xB5EF72DEu, 0xB6E3EB28u, 0xB765A7D3u,
  0xB85B59FDu, 0xB9DD1506u, 0xBAD18CF0u, 0xBB57C00Bu,
  0xBCC8BF1Cu, 0xBD4EF3E7u, 0xBE426A11u, 0xBFC426EAu,
  0xC02AE476u, 0xC1ACA88Du, 0xC2A0317Bu, 0xC3267D80u,
  0xC4B90297u, 0xC53F4E6Cu, 0xC633D79Au, 0xC7B59B61u,
  0xC88B654Fu, 0xC90D29B4u, 0xCA01B042u, 0xCB87FCB9u,
  0xCC1883AEu, 0xCD9ECF55u, 0xCE9256A3u, 0xCF141A58u,
  0xD0EFAAFFu, 0xD169E604u, 0xD2657FF2u, 0xD3E33309u,
  0xD47C4C1Eu, 0xD5FA00E5u, 0xD6F69913u, 0xD770D5E8u,
  0xD84E2BC6u, 0xD9C8673Du, 0xDAC4FECBu, 0xDB42B230u,
  0xDCDDCD27u, 0xDD5B81DCu, 0xDE57182Au, 0xDFD154D1u,
  0xE026359Fu, 0xE1A07964u, 0xE2ACE092u, 0xE32AAC69u,
  0xE4B5D37Eu, 0xE5339F85u, 0xE63F0673u, 0xE7B94A88u,
  0xE887B4A6u, 0xE901F85Du, 0xEA0D61ABu, 0xEB8B2D50u,
  0xEC145247u, 0xED921EBCu, 0xEE9E874Au, 0xEF18CBB1u,
  0xF0E37B16u, 0xF16537EDu, 0xF269AE1Bu, 0xF3EFE2E0u,
  0xF4709DF7u, 0xF5F6D10Cu, 0xF6FA48FAu, 0xF77C0401u,
  0xF842FA2Fu, 0xF9C4B6D4u, 0xFAC82F22u, 0xFB4E63D9u,
  0xFCD11CCEu, 0xFD575035u, 0xFE5BC9C3u, 0xFFDD8538u,
};

#define COMPUTE_CRC24Q(parse, data)  (((parse)->check << 8) ^ crc24q[data ^ (((parse)->check >> 16) & 0xff)])

#endif // _SPARKFUN_UNICORE_STRUCTS_H

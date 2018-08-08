// license:BSD-3-Clause
// copyright-holders:Robbbert
/***************************************************************************

Skeleton driver for numerous random terminals

2018-08-08

http://oldcomputer.info/terminal/



****************************************************************************/

#include "emu.h"
#include "cpu/z80/z80.h"


class terminal_state : public driver_device
{
public:
	terminal_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag)
		, m_maincpu(*this, "maincpu")
	{ }

	void terminal(machine_config &config);

private:

	void mem_map(address_map &map);
	required_device<cpu_device> m_maincpu;
};


void terminal_state::mem_map(address_map &map)
{
	map.unmap_value_high();
	map(0x0000, 0xffff).rom();
}



/* Input ports */
static INPUT_PORTS_START( terminal )
INPUT_PORTS_END


MACHINE_CONFIG_START( terminal_state::terminal )
	MCFG_DEVICE_ADD("maincpu", Z80, 4'000'000)
	MCFG_DEVICE_PROGRAM_MAP(mem_map)
MACHINE_CONFIG_END


/* ROM definition */

// for French Minitel network
ROM_START( alcat258 ) // MSM80C154 (+ TS9347// 8k ram // b&w
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "polish.bin",   0x0000, 0x8000, CRC(ce90f550) SHA1(fca5311704ca9e4d57414cfed96bb2a8ff73a145) )

	ROM_REGION( 0x0100, "user1", 0 )
	ROM_LOAD( "serial.bin",   0x0000, 0x0100, CRC(f0b99b8f) SHA1(906c285fd327eba2ba9798695acc456535b84570) )
ROM_END


ROM_START( alcat7100 ) // Z80  // 256k ram // b&w  // looks like it needs a boot floppy to start
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "rom.u117",                  0x0000, 0x0800, CRC(9c0debf7) SHA1(a042db34090656224ede41d8190f22f719d1a634) )
	ROM_LOAD( "906_513601_012gd2.u110",    0x0800, 0x0800, CRC(9346a41c) SHA1(6f7a2946494adac4d34874da9d5e475c99457000) ) // keyboard?

	ROM_REGION( 0x1000, "chargen", 0 ) // first half blank
	ROM_LOAD( "906_513301_rev00_ba6d.u20", 0x0000, 0x1000, CRC(143cfdfc) SHA1(4d924d1f16c30d72e1fdbb786488156bb9961442) )
ROM_END


ROM_START( ampex210 ) // Z80 (+6551,MC2672,3515260-01, 3 xtals, speaker) // 8k ram // amber
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "35-5960-03.u30", 0x0000, 0x8000, CRC(d3f86117) SHA1(f8a9b66899117b362b195bfc94c75bc902fb1376) )

	ROM_REGION( 0x1000, "chargen", 0 )
	ROM_LOAD( "35-526-01.u3",   0x0000, 0x1000, CRC(4659bcd2) SHA1(554574f55ed875baba0a6133648c44df763cc5c4) )
ROM_END


ROM_START( facit4440 ) // Z80 (+HD46505SP, 2x Z80ADART // 16k ram // b&w
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "rom7.bin",     0x0000, 0x4000, CRC(a8da2b11) SHA1(4436ef14c29ae299f7bc338748158771c02d02a9) )
	ROM_LOAD( "rom5.bin",     0xa000, 0x2000, CRC(715d02b6) SHA1(e304718dbdc8867ac01909fd2d027e5014a8c4f9) )

	ROM_REGION( 0x8000, "chargen", 0 ) // order unknown
	ROM_LOAD( "rom2.bin",     0x0000, 0x0800, CRC(9e1a190c) SHA1(fb08ee806f1056bcdfb5b08ea85995e1d3d01298) )
	ROM_LOAD( "rom1.bin",     0x0800, 0x1000, CRC(b503c173) SHA1(209bf59e2e9953179d04c4e768fc41574e039d36) )
	ROM_LOAD( "rom3.bin",     0x1800, 0x1000, CRC(a55a25d9) SHA1(c0d321e65f214adee01bf5f8c495b2518fa31b7b) )
	ROM_LOAD( "rom4.bin",     0x2800, 0x1000, CRC(52004ef8) SHA1(50d6e2eb48f60db3a3c9d206fc40d3294b6adc0e) )
	ROM_LOAD( "rom6.bin",     0x3800, 0x4000, CRC(790b7642) SHA1(688a80cbf011e5c14f501e11fe0e3bf64a85bbd7) )
ROM_END


ROM_START( itt9216 ) // MC68008P8, (+beeper, 701188-001, xtal 38.080)// 64k ram // colour
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "174054-007.u52", 0x0000, 0x2000, CRC(be1f85c8) SHA1(8c44ff6166c43b524f41133053fa82f5c48047d8) )

	ROM_REGION( 0x2000, "chargen", 0 )
	ROM_LOAD( "174055-004.u40", 0x0000, 0x2000, CRC(c8611425) SHA1(31fbdd6ff72a96c59277b6edac9a6360f6e1e49e) )
ROM_END


ROM_START( loewed ) // order unknown // i8031, i8051(xtal 11.000 next to it), ITT LOTTI // 64k ram + battery-backed nvram // b&w
	ROM_REGION( 0x28000, "maincpu", 0 )
	ROM_LOAD( "mainboard_18764_100.bin", 0x00000, 0x020000, CRC(f9ec7591) SHA1(1df7bdf33b8086166f1addb686a911a0c52dde32) )
	ROM_LOAD( "module_19315_056.bin",    0x20000, 0x008000, CRC(b333c5ed) SHA1(93cfa95e595bea83fe1b34a1426b80ceb1755c50) )
ROM_END


ROM_START( loewe715 ) // i8051, ITT LOTTI // 64k ram // colour
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "eprom.bin",    0x00000, 0x10000, CRC(2668b944) SHA1(b7773c4d7a1e0dde2a2b414ae76e5faa1fa5e324) )
ROM_END


ROM_START( t3210 ) // order unknown // i8031, 8742 // 4+2k ram onboard; 24kb in battery-backed expansion // b&w
	ROM_REGION( 0x12000, "maincpu", 0 )
	ROM_LOAD( "s22723_r121-c2-2.d11",     0x00000, 0x0800, CRC(f0eda00e) SHA1(6b0d9f5e9d99644c3be16cbf0c0d3b1ea05aabee) )
	ROM_LOAD( "d8742_s22723_r118-c1.d16", 0x00800, 0x0800, CRC(f334a2a3) SHA1(c1cd4d775c2984252e6869a4c8f99d56646b89e9) )
	ROM_LOAD( "s22723_r115-c1-6_ct.d6",   0x01000, 0x8000, CRC(d09fea94) SHA1(52168060093dfe964c0316d9ff335cd59da01d48) )
	ROM_LOAD( "s22723_r115-c2-6_ct.d7",   0x09000, 0x8000, CRC(6e1eaacd) SHA1(cfda25dbbeddc7c75379c4b0dc97addb602d79ef) )
	ROM_LOAD( "prom_s22723_r120-c1.bin",  0x11000, 0x0100, CRC(4460cd50) SHA1(fe36d758d64493cb5f8217fe51bbbe8203424fbe) )
ROM_END


ROM_START( feap90 ) // order unknown // i8031, i8742 (+SAA5351, 80C42C121) // 4+2k ram onboard; 24kb in battery-backed expansion // b&w
	ROM_REGION( 0x18000, "maincpu", 0 )
	ROM_LOAD( "s22723-r116-c25-6 ex.d6", 0x00000, 0x10000, CRC(8362778d) SHA1(30fbe45eaedc1ed2e7b189f12e2ba7c23ab75de7) )
	ROM_LOAD( "s22723-r116-c26-6 ex.d2", 0x10000, 0x08000, CRC(121622ba) SHA1(c447da13f88772ec7d26e55ca8822e2c2dc3ecef) )
ROM_END


ROM_START( ec7915 ) // Z80 // 6k ram // amber
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "50mp_0c10_30_lupper.bin", 0x0000, 0x0800, CRC(e019690f) SHA1(b0ce837a940ad82d2f39bd9d02e3c441cb9e83ed) )
	ROM_LOAD( "50mp_0810_40.bin",        0x0800, 0x0800, CRC(ed7f12d6) SHA1(b6f1da6a74f77cf1d392eee79f5ea168f3626ee5) )
	ROM_LOAD( "50mp_1010_49.bin",        0x1800, 0x0800, CRC(bfddf0e6) SHA1(dff4be8c0403519530e6c9106ab279a3037e074a) )
	ROM_LOAD( "50mp_1810_60.bin",        0x2000, 0x0800, CRC(759f2dc7) SHA1(515778ea213b9204f75f920ef1fbff6c14f9cf3c) )
	ROM_LOAD( "50mp_2c10_30_lower.bin",  0x5000, 0x0800, CRC(1ff59657) SHA1(777ef82e20a0100c0069ee5e7fbac5b3b86e3529) ) // keyboard rom?

	ROM_REGION( 0x0800, "chargen", 0 )
	ROM_LOAD( "char.bin",                0x0000, 0x0800, CRC(e75a6bc4) SHA1(04b56d1f5ab7f2145699555df5ac44d078804821) )
ROM_END


ROM_START( 7951om ) // TTL (no cpu) // 1k x 6bits display ram 64-characters uppercase only, screen 40x12 // green
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "prom1_rear.bin", 0x0000, 0x0100, CRC(ab231a4c) SHA1(1412d0e9163125f28a777717c4dd9d5fd54b5196) )
	ROM_LOAD( "prom2.bin",      0x0100, 0x0100, CRC(5d65b9b6) SHA1(2ea22beb6edbedb1d215b4c55233af897cdeb535) )

	ROM_REGION( 0x0800, "chargen", ROMREGION_INVERT )
	ROM_LOAD( "7951om.bin",     0x0000, 0x0800, CRC(36fc61c6) SHA1(6b5e8701b185b32a1a2630ddfc5402345628ecba) )
ROM_END


ROM_START( vdm79322 ) // Z80 (there's a 8255, 8253, UA857D) // 8k ram // b&w  // 8031 for kbd
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "27512_m322.bin",      0x00000, 0x10000, CRC(24573079) SHA1(b81c17e99493302054d78fbee2e416ab6493b5f3) )

	ROM_REGION( 0x4000, "user1", 0 )  // keyboard?
	ROM_LOAD( "27128_w322-3700.bin", 0x00000, 0x004000, CRC(e5e76ca2) SHA1(bb18c9fa29ef9fa0563aa07d2b856cf6594fc020) )
ROM_END


ROM_START( ikt5a ) // order unknown // 80C51 (+xtal 15.000) // 8k ram // RGB external, uses XT keyboard
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "g26.bin",      0x0000, 0x2000, CRC(657668be) SHA1(212a9eb1fb9b9c16f3cc606c6befbd913ddfa395) )
	ROM_LOAD( "ver_ih.bin",   0x2000, 0x4000, CRC(5a15b4e8) SHA1(cc0336892279b730f1596f31e129c5a898ecdc8f) )
ROM_END


ROM_START( teleguide ) // order unknown // i8051, i8031 (layout very similar to loewed) // 64k ram + battery-backed nvram // b&w
	ROM_REGION( 0x38000, "maincpu", 0 )
	ROM_LOAD( "cardreader_17044-068_349-1163.bin", 0x00000, 0x10000, CRC(3c980c0d) SHA1(9904ffd283a11defbe3daf2cb9029bcead8b02d0) )
	ROM_LOAD( "mainboard_18764-063_349-1173.bin",  0x10000, 0x20000, CRC(eb5c2d05) SHA1(dba2f72f928487e83741ad24d70b568e4510988e) )
	ROM_LOAD( "module_19315-051_349-01173.bin",    0x20000, 0x08000, CRC(29c4b49d) SHA1(9bf37616eb130cb6bf86954b4a4952ea99d43ce8) )
ROM_END


ROM_START( a1010 ) // 65SC02 (+ 4x 65SC22, 65SC51, SED1330F, xtal ??? + 6.400, 3.6v battery, RTC 58321A) // 32k + 8k + 8k ram // b&w LCD // This is a portable digital teletype machine
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "d15_31.bin",   0x0000, 0x8000, CRC(5ee1175d) SHA1(87ff6a3d5c64a53b0ab23d54aa343365c44d0407) )

	ROM_REGION( 0x8000, "chargen", 0 )
	ROM_LOAD( "chargen.bin",  0x0000, 0x8000, CRC(07daa70e) SHA1(8066a0ac238b06fbeeb99c3a2a8a9e70a27db7a9) )
ROM_END



/* Driver */

/*    YEAR  NAME       PARENT  COMPAT  MACHINE   INPUT     CLASS           INIT          COMPANY             FULLNAME                     FLAGS */
COMP( 1991, alcat258,  0,      0,      terminal, terminal, terminal_state, empty_init, "Alcatel",            "Terminatel 258",         MACHINE_IS_SKELETON )
COMP( 1984, alcat7100, 0,      0,      terminal, terminal, terminal_state, empty_init, "Alcatel",            "Terminal 7100",          MACHINE_IS_SKELETON )
COMP( 1989, ampex210,  0,      0,      terminal, terminal, terminal_state, empty_init, "Ampex",              "210+",                   MACHINE_IS_SKELETON )
COMP( 1986, facit4440, 0,      0,      terminal, terminal, terminal_state, empty_init, "Facit",              "Terminal 4440 (30M-F1)", MACHINE_IS_SKELETON )
COMP( 1986, itt9216,   0,      0,      terminal, terminal, terminal_state, empty_init, "ITT",                "Courier 9216-X",         MACHINE_IS_SKELETON )
COMP( 1992, loewed,    0,      0,      terminal, terminal, terminal_state, empty_init, "Loewe",              "Multitel D",             MACHINE_IS_SKELETON )
COMP( 1988, loewe715,  0,      0,      terminal, terminal, terminal_state, empty_init, "Loewe",              "Multicom 715L",          MACHINE_IS_SKELETON )
COMP( 1986, t3210,     0,      0,      terminal, terminal, terminal_state, empty_init, "Siemens",            "Bitel T3210",            MACHINE_IS_SKELETON )
COMP( 1986, feap90,    0,      0,      terminal, terminal, terminal_state, empty_init, "Siemens",            "Multitel Fe Ap 90-1.1",  MACHINE_IS_SKELETON )
COMP( 198?, ec7915,    0,      0,      terminal, terminal, terminal_state, empty_init, "Mera-Elzab",         "EC-7915 (EC-7950)",      MACHINE_IS_SKELETON )
COMP( 1987, 7951om,    0,      0,      terminal, terminal, terminal_state, empty_init, "Mera-Elzab",         "7951om",                 MACHINE_IS_SKELETON )
COMP( 1992, vdm79322,  0,      0,      terminal, terminal, terminal_state, empty_init, "Mera-Elzab",         "VDM79322",               MACHINE_IS_SKELETON )
COMP( 1993, ikt5a,     0,      0,      terminal, terminal, terminal_state, empty_init, "Creator / Fura Elektronik", "IKT-5A",          MACHINE_IS_SKELETON )
COMP( 1992, teleguide, 0,      0,      terminal, terminal, terminal_state, empty_init, "Loewe / Televerket", "Teleguide",              MACHINE_IS_SKELETON )
COMP( 1993, a1010,     0,      0,      terminal, terminal, terminal_state, empty_init, "Humantechnik", "Textel Compact A1010-0",       MACHINE_IS_SKELETON )

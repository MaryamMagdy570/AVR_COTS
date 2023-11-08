#ifndef _SPI_CONFIG_H_
#define _SPI_CONFIG_H_


/*Enable SPI Interrupt Mode*/
/*
 * ENABLED
 * DISABLED
 *
 */

#define SPI_INTERRUPT_MODE 	ENABLED

/*SPI Data Order*/
/*
 * LSB_FIRST
 * MSB_FIRST
 *
 */

#define SPI_DATA_ORDER  LSB_FIRST

/*Master or Slave Select*/
/*
 * MASTER
 * SLAVE
 *
 */

#define SPI_MASTER_SLAVE_MODE  MASTER
/*
 * Clock Polarity mode
 * IDLE_LOW >> leading edge is rising
 * IDLE_HIGH >> leading edge is falling
 *
 */
#define SPI_CLOCK_POLARITY  IDLE_LOW


/* Clock Phase Mode
 *
 * SAMPLE_AT_LEADING >> sample at leading and setup at trailing
 * SETUP_AT_LEADING >> sample at trailing and setup at rising
 *
 */

#define SPI_CLOCK_PHASE   SAMPLE_AT_LEADING
/* CLOCK
 *
 * MODE_F/4
 * MODE_F/2
 *
 */

#define SPI_FREQUENCY  DIVIDE_BY_4



#endif

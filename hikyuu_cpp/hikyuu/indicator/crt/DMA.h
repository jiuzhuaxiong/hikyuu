/*
 * DMA.h
 *
 *  Copyright (c) 2019, hikyuu.org
 *
 *  Created on: 2015-5-16
 *      Author: fasiondog
 */

#pragma once
#ifndef INDICATOR_CRT_DMA_H_
#define INDICATOR_CRT_DMA_H_

#include "REF.h"

namespace hku {

/**
 * 动态移动平均
 * @details
 * <pre>
 * 用法：DMA(X,A),求X的动态移动平均。
 * 算法：若Y=DMA(X,A) 则 Y=A*X+(1-A)*Y',其中Y'表示上一周期Y值。
 * 例如：DMA(CLOSE,VOL/CAPITAL)表示求以换手率作平滑因子的平均价
 * </pre>
 * @param ind1 待计算的数据
 * @param a 动态系数
 * @ingroup Indicator
 */
Indicator DMA(const Indicator& ind1, const Indicator& a);

inline Indicator DMA(const Indicator& ind1, const Indicator& a) {
    Indicator dma = a * ind1 + (1 - a) * REF(ind1, 1);
    dma.name("DMA");
    return dma;
}

}  // namespace hku

#endif /* INDICATOR_CRT_DMA_H_ */

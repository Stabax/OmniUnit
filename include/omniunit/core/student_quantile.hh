//student_quantile.hh

/*
Copyright (c) 2019, Denis Tosetto All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  Neither the name of Denis Tosetto nor the names
  of its contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef OMNIUNIT_STUDENT_QUANTILE_HH_
#define OMNIUNIT_STUDENT_QUANTILE_HH_


namespace omni
{



// these quantiles have been generated from LibreOffice calc version 5.0.5.2
// build 55b006a02d247b5f7215fc6ea0fde844b30035b3 with the function :
// LOI.STUDENT.INVERSE.BILATERALE(0,32; n)
// This means that there is a probability of 68% to be between -q and q
inline constexpr double studentQuantiles[500] =
{
  1.8190	,
  1.3116	,
  1.1889	,
  1.1344	,
  1.1037	,
  1.0840	,
  1.0703	,
  1.0602	,
  1.0525	,
  1.0464	,
  1.0415	,
  1.0374	,
  1.0340	,
  1.0311	,
  1.0285	,
  1.0263	,
  1.0244	,
  1.0227	,
  1.0212	,
  1.0198	,
  1.0186	,
  1.0174	,
  1.0164	,
  1.0155	,
  1.0146	,
  1.0138	,
  1.0131	,
  1.0124	,
  1.0118	,
  1.0112	,
  1.0107	,
  1.0102	,
  1.0097	,
  1.0092	,
  1.0088	,
  1.0084	,
  1.0080	,
  1.0076	,
  1.0073	,
  1.0070	,
  1.0067	,
  1.0064	,
  1.0061	,
  1.0058	,
  1.0056	,
  1.0053	,
  1.0051	,
  1.0049	,
  1.0047	,
  1.0044	,
  1.0042	,
  1.0041	,
  1.0039	,
  1.0037	,
  1.0035	,
  1.0034	,
  1.0032	,
  1.0031	,
  1.0029	,
  1.0028	,
  1.0026	,
  1.0025	,
  1.0024	,
  1.0022	,
  1.0021	,
  1.0020	,
  1.0019	,
  1.0018	,
  1.0017	,
  1.0016	,
  1.0015	,
  1.0014	,
  1.0013	,
  1.0012	,
  1.0011	,
  1.0010	,
  1.0009	,
  1.0008	,
  1.0008	,
  1.0007	,
  1.0006	,
  1.0005	,
  1.0005	,
  1.0004	,
  1.0003	,
  1.0002	,
  1.0002	,
  1.0001	,
  1.0000	,
  1.0000	,
  0.9999	,
  0.9999	,
  0.9998	,
  0.9997	,
  0.9997	,
  0.9996	,
  0.9996	,
  0.9995	,
  0.9995	,
  0.9994	,
  0.9994	,
  0.9993	,
  0.9993	,
  0.9992	,
  0.9992	,
  0.9991	,
  0.9991	,
  0.9991	,
  0.9990	,
  0.9990	,
  0.9989	,
  0.9989	,
  0.9989	,
  0.9988	,
  0.9988	,
  0.9987	,
  0.9987	,
  0.9987	,
  0.9986	,
  0.9986	,
  0.9986	,
  0.9985	,
  0.9985	,
  0.9985	,
  0.9984	,
  0.9984	,
  0.9984	,
  0.9983	,
  0.9983	,
  0.9983	,
  0.9982	,
  0.9982	,
  0.9982	,
  0.9982	,
  0.9981	,
  0.9981	,
  0.9981	,
  0.9981	,
  0.9980	,
  0.9980	,
  0.9980	,
  0.9980	,
  0.9979	,
  0.9979	,
  0.9979	,
  0.9979	,
  0.9978	,
  0.9978	,
  0.9978	,
  0.9978	,
  0.9977	,
  0.9977	,
  0.9977	,
  0.9977	,
  0.9977	,
  0.9976	,
  0.9976	,
  0.9976	,
  0.9976	,
  0.9976	,
  0.9975	,
  0.9975	,
  0.9975	,
  0.9975	,
  0.9975	,
  0.9974	,
  0.9974	,
  0.9974	,
  0.9974	,
  0.9974	,
  0.9974	,
  0.9973	,
  0.9973	,
  0.9973	,
  0.9973	,
  0.9973	,
  0.9973	,
  0.9972	,
  0.9972	,
  0.9972	,
  0.9972	,
  0.9972	,
  0.9972	,
  0.9972	,
  0.9971	,
  0.9971	,
  0.9971	,
  0.9971	,
  0.9971	,
  0.9971	,
  0.9971	,
  0.9970	,
  0.9970	,
  0.9970	,
  0.9970	,
  0.9970	,
  0.9970	,
  0.9970	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9969	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9968	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9967	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9966	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9965	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9964	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9963	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9962	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9961	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9960	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9959	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9958	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9957	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9956	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9955	,
  0.9954	,
  0.9954
};


constexpr double quantile(unsigned index)
{
  if(index<=499)
    return studentQuantiles[index-1];
  else
    return studentQuantiles[499];
}



} // namespace omni


#endif // OMNIUNIT_STUDENT_QUANTILE_HH_
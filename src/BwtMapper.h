/*
 * BwtMapper.h
 *
 *  Created on: 2014��7��9��
 *      Author: Administrator
 */

#ifndef BWTMAPPER_H_
#define BWTMAPPER_H_
#include "BwtIndexer.h"
#include "../libbwa/bwtaln.h"
#include "StatCollector.h"
#include <iostream>
#include <fstream>
#include "SamFileHeader.h"
#include "SamRecord.h"
#include "BamInterface.h"
#include "SamFile.h"
#ifndef BWAPE_H_
#include "../libbwa/bwape.h"
#endif
class BwtMapper
  {
    StatCollector collector;
    char *bwa_rg_line=0, *bwa_rg_id=0;
  public:

    BwtMapper();
    BwtMapper(BwtIndexer& BwtIndex,const std::string & Fastq_1, const std::string & Fastq_2, const std::string & VcfPath, const pe_opt_t* popt, const gap_opt_t * opt );
    BwtMapper(BwtIndexer& BwtIndex, const std::string & Fa_List, const std::string & VcfPath, const pe_opt_t* popt, const gap_opt_t * opt);
    int bwa_cal_pac_pos(BwtIndexer& BwtIndex, int n_seqs, bwa_seq_t *seqs, int max_mm, float fnr);
    int bwa_cal_pac_pos_pe(bwt_t *const _bwt[2], int n_seqs, bwa_seq_t *seqs[2],  isize_info_t *ii, const pe_opt_t *opt, const gap_opt_t *gopt, const isize_info_t *last_ii);
    //static void bwa_cal_sa_reg_gap(int tid, bwt_t *const bwt[2], int n_seqs, bwa_seq_t *seqs, const gap_opt_t *opt);
    bool SingleEndMapper(BwtIndexer& BwtIndex,const char *fn_fa, const std::string & VcfPath, const gap_opt_t * opt,SamFileHeader& SFH, BamInterface & BamIO, IFILE BamFile, StatGenStatus& StatusTracker, std::ofstream& fout, int &total_add);
    bool PairEndMapper(BwtIndexer& BwtIndex,const char *fn_fa1,const char * fn_fa2, const std::string & VcfPath, const  pe_opt_t *popt,const gap_opt_t* opt,SamFileHeader& SFH, BamInterface & BamIO, IFILE BamFile, StatGenStatus& StatusTracker, std::ofstream& fout, int &total_add);
    bool IsFP(const std::string &seq, const std::string &qual, const char * );

    bool SetSamRecord(const bntseq_t *bns, bwa_seq_t *p, const bwa_seq_t *mate, int mode, int max_top2, SamFileHeader& SFH,SamRecord & SR);
    bool SetSamFileHeader(SamFileHeader& SFH, const bntseq_t * bns);

    int bwa_set_rg(const char *s);
    virtual ~BwtMapper();

    inline void  revealopt(const gap_opt_t* opt)
    {
      std::cerr<<opt->s_mm<<std::endl;
      std::cerr<<opt->s_gapo<<std::endl;
      std::cerr<<opt->s_gape<<std::endl;
      std::cerr<<opt->mode<<std::endl
      <<opt->indel_end_skip<<std::endl
      <<opt->max_del_occ<<std::endl
      <<opt->max_entries<<std::endl
      <<opt->fnr<<std::endl
      <<opt->max_diff<<std::endl
      <<opt->max_gapo<<std::endl
      <<opt->max_gape<<std::endl
      <<opt->max_seed_diff<<std::endl
      <<opt->seed_len<<std::endl
      <<opt->n_threads<<std::endl
      <<opt->max_top2<<std::endl
      <<opt->trim_qual<<std::endl
      <<"opt reveal end"<<std::endl;

    }
  };

#endif /* BWTMAPPER_H_ */
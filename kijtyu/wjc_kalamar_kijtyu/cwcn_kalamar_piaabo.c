#include "cwcn_kalamar_piaabo.h"
__kalamar_t *kalamar_fabric(void *_wikimyei){
    __kalamar_t *new_kalamar=malloc(sizeof(__kalamar_t));
    new_kalamar->__kl_level=__KL_0;
    new_kalamar->__wikimyei=_wikimyei;
    new_kalamar->__kl_stdin=stdin;
    new_kalamar->__kl_stdout=stdout; // #FIXME (stdscr) aka stdout
    new_kalamar->__kl_stdscr=initscr();
    new_kalamar->__kl_item=malloc(_BUGGER_KALAMAR_LEVELS_N_*sizeof(int));
    new_kalamar->__kl_item_max=malloc(_BUGGER_KALAMAR_LEVELS_N_*sizeof(int));
    for(unsigned int _idx=0x00:_idx<_BUGGER_KALAMAR_LEVELS_N_;_idx++){new_kalamar->__kl_item[_idx]=0x00}
    for(unsigned int _idx=0x00:_idx<_BUGGER_KALAMAR_LEVELS_N_;_idx++){new_kalamar->__kl_item_max[_idx]=0x00}
    update_screen_dims(new_kalamar);
    noecho();
    // start_color();
    keypad(new_kalamar->__kl_stdscr,TRUE);
    return new_kalamar;
}
void fill_itm_idx(__kalamar_t *_kalamar){
    
}
void klmg_key(__kalamar_t *_kalamar){
    switch(_kalamar->__kl_level){
    case __KL_0:get_itm_key_level_start(c_kalamar);
    case __KL_1:
    switch(_kalamar->__kl_item[_kalamar->__kl_level]){
        case __KL_KALAMAR:
        case __KL_WIKIMYEI:
        case __KL_JKIMYEI:
        case __KL_LOAD:
        case __KL_ALLIU:
        case __KL_UWAABO:
        case __KL_ENTROPY:
        case __KL_TSANE:
        case __KL_MUNAAJPI:
        case __KL_DUURUVA:klmp_duuruva(_kalamar,_klmduuruva);
        default:klmp_problem(_kalamar,">> > <.> f kalamar item unregnized");break;
    case __KL_2:
    case __KL_3:
    default:mvwprintw(_kalamar->__kl_stdscr,2,10,"Charcter pressed is = %3d Hopefully is can be printed as '%c'",_user_key,_user_key);break;
    }
}
void get_itm_key_level_start(__kalamar_t *_kalamar){
    int _user_key;
    _user_key=wgetch(_kalamar->__kl_stdscr);
    switch(_user_key){
    case KEY_UP:if(_kalamar->__kl_item[_kalamar->__kl_level]>0){_kalamar->__kl_item[_kalamar->__kl_level]--;}else{_kalamar->__kl_item[_kalamar->__kl_level]=_kalamar->__kl_item_max[_kalamar->__kl_level];}break;
    case KEY_DOWN:if(_kalamar->__kl_item[_kalamar->__kl_level]<_kalamar->__kl_item_max[_kalamar->__kl_level]){_kalamar->__kl_item[_kalamar->__kl_level]++;}else{_kalamar->__kl_item[_kalamar->__kl_level]=0;}break;
    case 261:_kalamar->__kl_level++;break;
    case 260:_kalamar->__kl_level=__KL_0;break;
    case 339:break;// #FIXME load_go_up
    case 338:break;// #FIXME load_go_down
    default:mvwprintw(_kalamar->__kl_stdscr,2,10,"Charcter pressed is = %3d Hopefully is can be printed as '%c'",_user_key,_user_key);break;
    }
}
void get_itm_key_level_mid(__kalamar_t *_kalamar){
    int _user_key;
    _user_key=wgetch(_kalamar->__kl_stdscr);
    switch(_user_key){
    case KEY_UP:if(_kalamar->__kl_item[_kalamar->__kl_level]>0){_kalamar->__kl_item[_kalamar->__kl_level]--;}else{_kalamar->__kl_item[_kalamar->__kl_level]=_kalamar->__kl_item_max[_kalamar->__kl_level];}break;
    case KEY_DOWN:if(_kalamar->__kl_item[_kalamar->__kl_level]<_kalamar->__kl_item_max[_kalamar->__kl_level]){_kalamar->__kl_item[_kalamar->__kl_level]++;}else{_kalamar->__kl_item[_kalamar->__kl_level]=0;}break;
    case 261:_kalamar->__kl_level++;break;
    case 260:_kalamar->__kl_level--;break;
    case 339:break;// #FIXME load_go_up
    case 338:break;// #FIXME load_go_down
    default:mvwprintw(_kalamar->__kl_stdscr,2,10,"Charcter pressed is = %3d Hopefully is can be printed as '%c'",_user_key,_user_key);break;
    }
}
void goto_klm_itm_0(__kalamar_t *_kalamar){
    switch(_kalamar->__item_0){
    case __KL_KALAMAR:  move(0x01+_DALTA_V_*0X01,0X01+_DALTA_H_*0X00);break;
    case __KL_WIKIMYEI: move(0x01+_DALTA_V_*0X02,0X01+_DALTA_H_*0X00);break;
    case __KL_JKIMYEI:  move(0x01+_DALTA_V_*0X03,0X01+_DALTA_H_*0X00);break;
    case __KL_LOAD:     move(0x01+_DALTA_V_*0X04,0X01+_DALTA_H_*0X00);break;
    case __KL_ALLIU:    move(0x01+_DALTA_V_*0X05,0X01+_DALTA_H_*0X00);break;
    case __KL_UWAABO:   move(0x01+_DALTA_V_*0X06,0X01+_DALTA_H_*0X00);break;
    case __KL_ENTROPY:  move(0x01+_DALTA_V_*0X07,0X01+_DALTA_H_*0X00);break;
    case __KL_TSANE:    move(0x01+_DALTA_V_*0X08,0X01+_DALTA_H_*0X00);break;
    case __KL_MUNAAJPI: move(0x01+_DALTA_V_*0X09,0X01+_DALTA_H_*0X00);break;
    case __KL_DUURUVA:  move(0x01+_DALTA_V_*0X0A,0X01+_DALTA_H_*0X00);break;
    default:klmp_problem(_kalamar,">> > <.> g kalamar item unregnized");break;
    }
}
void goto_klm_duuruva(__kalamar_t *_kalamar){
    switch(_kalamar->__kl_duuruva){
    case __KL_ALLIU_DUURUVA_STATE:      move(0x01+_DALTA_V_*0X01,0X01+_DALTA_H_*0X01);break;
    case __KL_MUNAAJPI_DUURUVA_STATE:   move(0x01+_DALTA_V_*0X02,0X01+_DALTA_H_*0X01);break;
    case __KL_ADVENTAGE_DUURUVA_STATE:  move(0x01+_DALTA_V_*0X03,0X01+_DALTA_H_*0X01);break;
    default:klmp_problem(_kalamar,">> > <.> g kalamar item unregnized");break;
    }
}
void klmp_level_0(__kalamar_t *_kalamar,__kalamar_itm_t _klmitm){
    switch(_klmitm){
    case __KL_KALAMAR:  goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"KALAMAR");break;
    case __KL_WIKIMYEI: goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"WIKIMYEI");break;
    case __KL_JKIMYEI:  goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"JKIMYEI");break;
    case __KL_LOAD:     goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"LOAD");break;
    case __KL_ALLIU:    goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"ALLIU");break;
    case __KL_UWAABO:   goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"UWAABO");break;
    case __KL_ENTROPY:  goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"ENTROPY");break;
    case __KL_TSANE:    goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"TSANE");break;
    case __KL_MUNAAJPI: goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"MUNAAJPI");break;
    case __KL_DUURUVA:  goto_klm_itm_0(_kalamar);wprintw(_kalamar->__kl_stdscr,"DUURUVA");break;
    default:klmp_problem(_kalamar,">> > <.> p kalamar item unregnized");break;
    }
}
void klmp_duuruva(__kalamar_t *_kalamar,__kalamar_duuruva_t _klmduuruva){
    switch(_klmduuruva){
    case __KL_ALLIU_DUURUVA_STATE:      goto_klm_duuruva(_kalamar,_klmduuruva);wprintw(_kalamar->__kl_stdscr,"ALLIU_DUURUVA");break;
    case __KL_MUNAAJPI_DUURUVA_STATE:   goto_klm_duuruva(_kalamar,_klmduuruva);wprintw(_kalamar->__kl_stdscr,"MUNAAJPI_DUURUVA");break;
    case __KL_ADVENTAGE_DUURUVA_STATE:  goto_klm_duuruva(_kalamar,_klmduuruva);wprintw(_kalamar->__kl_stdscr,"ADVENTAGE_DUURUVA");break;
    default:klmp_problem(_kalamar,">> > <.> p kalamar item unregnized");break;
    }
}
void update_screen_dims(__kalamar_t *_kalamar){
    getmaxyx(_kalamar->__kl_stdscr,_kalamar->__nrow,_kalamar->__ncol); 
}
void kill_kalamar(__kalamar_t *_kalamar){
    endwin();
    free(_kalamar);
}
/**/
void klmp_get_stdin(__kalamar_t *_kalamar){
    // raw();
    // cbreak();
    halfdelay(2);
}
void klmp_clear_stdout(__kalamar_t *_kalamar){
    fprintf(_kalamar->__kl_stdout,"%s",_GUI_CLEAR_SCREEN_);
}
void klmp_kalamar_level_0(__kalamar_t *_kalamar){
    update_screen_dims(_kalamar);
    // klmp_clear_stdout(_kalamar);
    box(_kalamar->__kl_stdscr,ACS_VLINE,ACS_HLINE);
    // attron(COLOR_PAIR(4));
    for(__kalamar_itm_t _idx=__KL_KALAMAR;_idx<=__KL_DUURUVA;_idx++){
        if(_idx==_kalamar->__kl_item[_kalamar->__kl_level]){attron(A_STANDOUT);}
        klmp_itm(_kalamar,_idx);
        if(_idx==_kalamar->__kl_item[_kalamar->__kl_level]){attroff(A_STANDOUT);}
    }
    mvwvline(_kalamar->__kl_stdscr,0x01,0x01*_DALTA_H_,ACS_VLINE,_kalamar->__nrow-0x02);
    wrefresh(_kalamar->__kl_stdscr);
}
void klmp_clear_stdin(__kalamar_t *_kalamar){
}
void klmp_help(__kalamar_t *_kalamar){
}
void klmp_problem(__kalamar_t *_kalamar, char *_problem){
    mvwprintw(_kalamar->__kl_stdscr,0x00,0x00,"%s",_problem);
    wrefresh(_kalamar->__kl_stdscr);
}
void kalamar_gui(__kalamar_t *_kalamar){
    // fflush(stdin); // #FIXME
    // fflush(_kalamar->__kl_stdout); // #FIXME

    switch(_kalamar->__kl_level){
    case __KL_0:
        klmp_kalamar_level_0(_kalamar);break;
    default:
        klmp_problem(_kalamar,">> > <.> kalamar level unregnized for KALAMAR itm");
        break;
    }
    // break;
    // switch(_kalamar->__kl_item[_kalamar->__kl_level]){
    // case __KL_KALAMAR:
    // default:
    //     klmp_problem(_kalamar,">> > <.> c kalamar item unregnized");
    //     break;
    // }
    
}
// void kalamar_get_load_item_from_index(__kalamar_t *_kalamar,);
void print_kamar_seven(__kalamar_t *_kalamar){

}
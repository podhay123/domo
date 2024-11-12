//WIN1
                if (p1 == 'a'){
                    win_a = win_a + 1;
                }
                if (p1 == 'b'){
                    win_b = win_b + 1;
                }
                if (p1 == 'c'){
                    win_c = win_c + 1;
                }
                if (p1 == 'd'){
                    win_d = win_d + 1;
                }
                if (p2 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p2 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p2 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p2 == 'd'){
                    loose_d = loose_d + 1;
                }
//WIN2
                if (p1 == 'a'){
                    loose_a = loose_a + 1;
                }
                if (p1 == 'b'){
                    loose_b = loose_b + 1;
                }
                if (p1 == 'c'){
                    loose_c = loose_c + 1;
                }
                if (p1 == 'd'){
                    loose_d = loose_d + 1;
                }
                if (p2 == 'a'){
                    win_a = win_a + 1;
                }
                if (p2 == 'b'){
                    win_b = win_b + 1;
                }
                if (p2 == 'c'){
                    win_c = win_c + 1;
                }
                if (p2 == 'd'){
                    win_d = win_d + 1;
                }
//DRAW
                if (f1>f2){
                    if (p1 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p1 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p1 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p1 == 'd'){
                        win_d = win_d + 1;
                    }
                    if (p2 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p2 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p2 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p2 == 'd'){
                        loose_d = loose_d + 1;
                    }
                }
                if (f1<f2){
                
                    if (p1 == 'a'){
                        loose_a = loose_a + 1;
                    }
                    if (p1 == 'b'){
                        loose_b = loose_b + 1;
                    }
                    if (p1 == 'c'){
                        loose_c = loose_c + 1;
                    }
                    if (p1 == 'd'){
                        loose_d = loose_d + 1;
                    }
                    if (p2 == 'a'){
                        win_a = win_a + 1;
                    }
                    if (p2 == 'b'){
                        win_b = win_b + 1;
                    }
                    if (p2 == 'c'){
                        win_c = win_c + 1;
                    }
                    if (p2 == 'd'){
                        win_d = win_d + 1;
                    }
                }
                if(f1==f2){
                    if (p1 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p1 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p1 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p1 == 'd'){
                        draw_d = draw_d + 1;
                    }
                    if (p2 == 'a'){
                        draw_a = draw_a + 1;
                    }
                    if (p2 == 'b'){
                        draw_b = draw_b + 1;
                    }
                    if (p2 == 'c'){
                        draw_c = draw_c + 1;
                    }
                    if (p2 == 'd'){
                        draw_d = draw_d + 1;
                    }
                }

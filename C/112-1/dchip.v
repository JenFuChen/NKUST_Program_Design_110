module FINAL(CLK, RST, DATA, ADD, ADD_1, ADD_2, D_1, SUB_1, SUB_2, D_2, D_3, D_4, L_D_1, L_D_2, L_D_3, L_D_4, L_D_5);
    input   CLK;
    input   RST;
    output  reg    [7:0]   DATA;

    output  reg    [3:0]   ADD;
    output  reg    [7:0]   ADD_1;
    output  reg    [7:0]   ADD_2;
    
    output  reg    [7:0]   SUB_1;
    output  reg    [7:0]   SUB_2;

    output  reg    [7:0]   D_1;
    output  reg    [7:0]   D_2;
    output  reg    [7:0]   D_3;
    output  reg    [7:0]   D_4;

    output  reg    [7:0]   L_D_1;
    output  reg    [7:0]   L_D_2;
    output  reg    [7:0]   L_D_3;
    output  reg    [7:0]   L_D_4;
    output  reg    [7:0]   L_D_5;

    always@(negedge CLK) begin
        if(!RST)begin
            ADD <= 4'h0;
        end else begin
            ADD <= ADD + 1;
        end
    end
    
    always @(ADD) begin
        case ( ADD )
            4'd0 : DATA = 8'h0 ;
            4'd1 : DATA = 8'h0A ;
            4'd2 : DATA = 8'h28 ;
            4'd3 : DATA = 8'h14 ;
            4'd4 : DATA = 8'h32 ;
            4'd5 : DATA = 8'h1e ;
            4'd6 : DATA = 8'h3c ;
            4'd7 : DATA = 8'h1c ;
            4'd8 : DATA = 8'h2e ;
            4'd9 : DATA = 8'h12 ;
            4'd10 : DATA = 8'h14 ;
            4'd11 : DATA= 8'h0c;
            4'd12 : DATA = 8'h22;
            4'd13: DATA = 8'h0a;
            4'd14: DATA = 8'h10;
            4'd15: DATA = 8'h08 ;
            default: DATA = 8'h0;
        endcase
    end

    always@(negedge CLK )begin
        if (ADD % 2 == 0) begin
            D_1 <= 8'hzz;
        end else begin
            D_1 <= DATA / 2;
        end

        D_2 <= SUB_1;
        D_3 <= D_2;
        D_4 <= SUB_2;

        L_D_1 <= DATA;
        L_D_2 <= L_D_1;
        L_D_3 <= ADD_1;
        L_D_4 <= L_D_3;
        L_D_5 <= ADD_2;

    end

    always@(*)begin
        SUB_1 <= DATA - D_1;
        SUB_2 <= D_3 - D_1;
        
        ADD_1 <= L_D_2 + (D_4 / 4);
        ADD_2 <= L_D_4 + (D_4 / 4);
    end

endmodule

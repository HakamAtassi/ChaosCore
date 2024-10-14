`ifndef CPU_IO_DRIVER
`define CPU_IO_DRIVER

class cpu_io_driver extends uvm_driver #(cache_req, cache_rsp);

    `uvm_component_utils(cpu_io_driver)

    virtual instruction_cache_if cache_vif;

    cache_req req;
    cache_rsp rsp;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if(!uvm_config_db #(virtual instruction_cache_if)::get(this, "", "cache_vif", cache_vif)) begin 
            `uvm_error("ENV", "Failed to get cache interface") 
        end

    endfunction

    task run_phase(uvm_phase phase);
        
        forever begin
            @(negedge cache_vif.clock);
            cache_vif.io_CPU_response_ready = 0;
            seq_item_port.try_next_item(req);
            if (req!=null) begin
                seq_item_port.item_done();
                cache_vif.reset = req.reset;
                cache_vif.io_CPU_request_valid = req.io_CPU_request_valid;
                cache_vif.io_CPU_request_bits_addr = req.io_CPU_request_bits_addr;
                //cache_vif.io_CPU_request_bits_wr_data = req.io_CPU_request_bits_wr_data;
                //cache_vif.io_CPU_request_bits_wr_en = req.io_CPU_request_bits_wr_en;
                cache_vif.io_CPU_response_ready = req.io_CPU_response_ready;


                cache_vif.io_flush_bits_is_misprediction = req.io_flush_bits_is_misprediction;
                cache_vif.io_flush_bits_is_exception = req.io_flush_bits_is_exception;
                cache_vif.io_flush_bits_is_fence = req.io_flush_bits_is_fence;
                cache_vif.io_flush_bits_is_CSR = req.io_flush_bits_is_CSR;
                cache_vif.io_flush_bits_flushing_PC = req.io_flush_bits_flushing_PC;
                cache_vif.io_flush_bits_redirect_PC = req.io_flush_bits_redirect_PC;
                cache_vif.io_flush_valid = req.io_flush_valid;

                cache_vif.added_delay = req.added_delay;

                rsp = new;
                rsp.set_id_info(req);
            end

            @(posedge cache_vif.clock);
            #1;
            if (cache_vif.io_CPU_response_valid) begin
                rsp.io_CPU_request_ready = cache_vif.io_CPU_request_ready;
                rsp.io_CPU_response_valid = cache_vif.io_CPU_response_valid;
                rsp.io_CPU_response_bits_fetch_PC = cache_vif.io_CPU_response_bits_fetch_PC;
                rsp.io_CPU_response_bits_valid_bits_0 = cache_vif.io_CPU_response_bits_valid_bits_0;
                rsp.io_CPU_response_bits_valid_bits_1 = cache_vif.io_CPU_response_bits_valid_bits_1;
                rsp.io_CPU_response_bits_valid_bits_2 = cache_vif.io_CPU_response_bits_valid_bits_2;
                rsp.io_CPU_response_bits_valid_bits_3 = cache_vif.io_CPU_response_bits_valid_bits_3;
                rsp.io_CPU_response_bits_instructions_0_instruction = cache_vif.io_CPU_response_bits_instructions_0_instruction;
                rsp.io_CPU_response_bits_instructions_0_packet_index = cache_vif.io_CPU_response_bits_instructions_0_packet_index;
                rsp.io_CPU_response_bits_instructions_0_ROB_index = cache_vif.io_CPU_response_bits_instructions_0_ROB_index;
                rsp.io_CPU_response_bits_instructions_1_instruction = cache_vif.io_CPU_response_bits_instructions_1_instruction;
                rsp.io_CPU_response_bits_instructions_1_packet_index = cache_vif.io_CPU_response_bits_instructions_1_packet_index;
                rsp.io_CPU_response_bits_instructions_1_ROB_index = cache_vif.io_CPU_response_bits_instructions_1_ROB_index;
                rsp.io_CPU_response_bits_instructions_2_instruction = cache_vif.io_CPU_response_bits_instructions_2_instruction;
                rsp.io_CPU_response_bits_instructions_2_packet_index = cache_vif.io_CPU_response_bits_instructions_2_packet_index;
                rsp.io_CPU_response_bits_instructions_2_ROB_index = cache_vif.io_CPU_response_bits_instructions_2_ROB_index;
                rsp.io_CPU_response_bits_instructions_3_instruction = cache_vif.io_CPU_response_bits_instructions_3_instruction;
                rsp.io_CPU_response_bits_instructions_3_packet_index = cache_vif.io_CPU_response_bits_instructions_3_packet_index;
                rsp.io_CPU_response_bits_instructions_3_ROB_index = cache_vif.io_CPU_response_bits_instructions_3_ROB_index;
                rsp.io_CPU_response_bits_prediction_hit = cache_vif.io_CPU_response_bits_prediction_hit;
                rsp.io_CPU_response_bits_prediction_target = cache_vif.io_CPU_response_bits_prediction_target;
                rsp.io_CPU_response_bits_prediction_br_type = cache_vif.io_CPU_response_bits_prediction_br_type;
                rsp.io_CPU_response_bits_prediction_T_NT = cache_vif.io_CPU_response_bits_prediction_T_NT;
                rsp.io_CPU_response_bits_GHR = cache_vif.io_CPU_response_bits_GHR;
                rsp.io_CPU_response_bits_NEXT = cache_vif.io_CPU_response_bits_NEXT;
                rsp.io_CPU_response_bits_TOS = cache_vif.io_CPU_response_bits_TOS;
                seq_item_port.put_response(rsp);
            end

        end
    endtask

endclass

`endif